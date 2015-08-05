#!/bin/bash

return_value=0
logdir="/tmp/bestofjava"
if ! mkdir $logdir; then
    echo "failed to create directory $logdir. bailing out"
    exit 1
fi


xmlFile=`find /usr -name '*.xml' -printf "%k %p\n" | sort -n | tail -1 | awk '{ print $2 }'`
valgrind --version >/dev/null 2>&1 || { echo >&2 "you need valgrind, but it's not installed. bailing out"; exit 1; }
cppLogFile="${logdir}/cpptest.txt"

javac -version >/dev/null 2>&1 || { echo >&2 "you need a java compiler, but it's not installed. on debian gnu/linux it's as simple as sudo apt-get install openjdk-8-jdk. bailing out"; exit 1; }
javac -d $logdir -Werror ${srcdir}/SimpleTester.java
if [ "$?" -ne 0 ]; then
    echo "failed to compile ${srcdir}/SimpleTester.java"
    exit 2
fi

javaLogFile="${logdir}/javatest.txt"
java -classpath $logdir SimpleTester $xmlFile > $javaLogFile &

valgrind ./simple_tester $xmlFile > $cppLogFile 2> "${logdir}/valgrind.txt"

while [ ! -f $javaLogFile ]
do
  echo "waiting for tests to finalize. stay tuned"
  sleep 1
done

leaks=`grep 'All heap blocks were freed -- no leaks are possible' ${logdir}/valgrind.txt | wc -l`

if [ "$leaks" -eq 0 ]; then
    echo "you have memory leaks!"
    return_value=3
fi

valgrindErrors=`grep 'ERROR SUMMARY: 0 errors from 0 contexts' ${logdir}/valgrind.txt | wc -l`
if [ "$valgrindErrors" -eq 0 ]; then
    echo "valgrind reports errors"
    return_value=2
fi


my_diff=`diff $cppLogFile $javaLogFile`
if [ "$?" -ne 0 ]; then
    echo "the difference between $cppLogFile and $javaLogFile is $my_diff"
    return_value=5
fi

cppTimeNow=`head -1 ${logdir}/cpp_time.txt`
javaTimeNow=`head -1 ${logdir}/java_time.txt`

timeDiff0=`expr $javaTimeNow - $cppTimeNow`

if [ $timeDiff0 -gt 2000 ]; then
    echo "time difference between java time and c++ time is $timeDiff0 milliseconds, which _may_ be considered too much."
    return_value=1
fi

cppTimeSet=`tail -1 ${logdir}/cpp_time.txt`
javaTimeSet=`tail -1 ${logdir}/java_time.txt`

timeDiff1=`expr $javaTimeSet - $cppTimeSet`

if [ $timeDiff1 -gt 2000 ]; then
    echo "time difference between java time and c++ time is $timeDiff1 milliseconds, which _may_ be considered too much."
    return_value=1
fi



#if all tests passed, let's remove our log directory
#if something failed, let's keep it
if [ $return_value -eq 0 ]; then
    rm -rf $logdir
fi

exit $return_value

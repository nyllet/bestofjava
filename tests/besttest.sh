#!/bin/bash

return_value=0
logdir="/tmp/bestofjava"
mkdir $logdir
g++ -v >/dev/null 2>&1 || { echo >&2 "you need g++, but it's not installed. bailing out"; exit 1; }

bestofjavalib=`find /usr -name libbestofjava.so`
if [ "x$bestofjavalib" == "x" ]; then
    echo >&2 "you need to build the bestofjava shared library before running this test. it's as simple as cd .. && make"
    exit 1
fi

expatlib=`find /usr -name libexpat.so`
if [ "x$expatlib" == "x" ]; then
    echo >&2 "you need to install the expat shared library before running this test. on debian gnu/linux it's as simple as sudo apt-get install libexpat1-dev"
    exit 1
fi

g++ -g ${srcdir}/SimpleTester.cpp -lbestofjava -lexpat

if [ $? -ne 0 ]; then
    echo "failed to compile SimpleTester.cpp. maybe your library path is not correctly setup? or could it be that libexpat1 is not installed?"
    exit 1
fi

xmlFile=`find /usr -name '*.xml' -printf "%k %p\n" | sort -n | tail -1 | awk '{ print $2 }'`
valgrind --version >/dev/null 2>&1 || { echo >&2 "you need valgrind, but it's not installed. bailing out"; exit 1; }
cppLogFile="${logdir}/cpptest.txt"

javac -version >/dev/null 2>&1 || { echo >&2 "you need a java compiler, but it's not installed. on debian gnu/linux it's as simple as sudo apt-get install openjdk-7-jdk. bailing out"; exit 1; }
javac -d $logdir ${srcdir}/SimpleTester.java
java -version >/dev/null 2>&1 || { echo >&2 "you need a java compiler, but it's not installed. on debian gnu/linux it's as simple as sudo apt-get install openjdk-7-jdk. bailing out"; exit 1; }
javaLogFile="${logdir}/javatest.txt"
java -classpath $logdir SimpleTester $xmlFile > $javaLogFile &

valgrind ./a.out $xmlFile > $cppLogFile 2> "${logdir}/valgrind.txt" 

while [ ! -f $javaLogFile ]
do
  echo "waiting for tests to finalize. stay tuned"
  sleep 1
done

leaks=`grep 'All heap blocks were freed -- no leaks are possible' ${logdir}/valgrind.txt | wc -l`

if [ "$leaks" -ne 1 ]; then
    echo "you have memory leaks!"
    return_value=3
fi

valgrindErrors=`grep 'ERROR SUMMARY: 0 errors from 0 contexts' ${logdir}/valgrind.txt | wc -l`
if [ "$valgrindErrors" -ne 1 ]; then
    echo "valgrind reports errors"
    return_value=2
fi


difference=`diff $cppLogFile $javaLogFile`
if [ "$return_value" -eq 0 ]; then
    return_value=$difference
fi

cppTime=`cat ${logdir}/cpp_time.txt`
javaTime=`cat ${logdir}/java_time.txt`

timeDiff=`expr $javaTime - $cppTime`

if [ $timeDiff -gt 3000 ]; then 
    echo "time difference between java time and c++ time is $timeDiff milliseconds, which _may_ be considered too much."
    return_value=1
fi

#if all tests passed, let's remove our log directory
#if something failed, let's keep it
if [ ! $return_value ]; then
    rm -rf $logdir
fi

exit $return_value

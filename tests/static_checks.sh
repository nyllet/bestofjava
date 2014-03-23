#!/bin/bash

cppcheck --version >/dev/null 2>&1 || { echo >&2 "you need cppcheck, but it's not installed. bailing out"; exit 1; }
if [[ $srcdir == *tests ]]
then
    mySrcDir="${srcdir/tests/src}"
else
    mySrcDir="${srcdir}"
fi
cppcheck $mySrcDir --enable=all --error-exitcode=5

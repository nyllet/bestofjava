#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.72])
AC_INIT([bestofjava], [0.0.1])
AC_CONFIG_SRCDIR([src/java/util/Calendar.cpp])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])
# Checks for programs.
AC_PROG_AWK
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_MAKE_SET

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AX_CHECK_COMPILE_FLAG([-std=c++26], [CXX="$CXX -std=c++26"], [AX_CHECK_COMPILE_FLAG([-std=c++2x], [CXX="$CXX -std=c++2x"], [AX_CHECK_COMPILE_FLAG([-std=c++23], [CXX="$CXX -std=c++23"],[AX_CHECK_COMPILE_FLAG([-std=c++2b], [CXX="$CXX -std=c++2b"], AC_MSG_ERROR([your compiler does not support c++23. please upgrade it. gcc 14.2 or clang 19 or any later version of them will do the job]))])])])

AC_CHECK_LIB(curl, curl_easy_init, [], [
echo "Error! You need libcurl."
exit -1
])

AC_CHECK_LIB(expat, XML_ParserCreate, [], [
echo "Error! You need libexpat1-dev."
exit -1             
])

AC_CHECK_SIZEOF([long])

# Checks for library functions.
AC_FUNC_MKTIME
AC_CHECK_FUNCS([gettimeofday localtime_r])

LT_PREREQ([2.5.4])
LT_INIT([disable-static])

AC_CONFIG_FILES([Makefile
                src/Makefile
                src/java/Makefile
                src/java/io/Makefile
                src/java/lang/Makefile
                src/java/net/Makefile
                src/java/util/Makefile
                src/org/xml/sax/Makefile
                src/org/xml/sax/helpers/Makefile
                src/javax/xml/parsers/Makefile
                tests/Makefile])
AC_OUTPUT

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
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

AC_CHECK_LIB(expat, XML_ParserCreate, [], [
echo "Error! You need libexpat."
exit -1             
])

# Checks for library functions.
AC_FUNC_MKTIME
AC_CHECK_FUNCS([gettimeofday localtime_r])

LT_INIT([disable-static])

AC_CONFIG_FILES([Makefile
                src/Makefile
                src/java/Makefile
                src/java/io/Makefile
                src/java/lang/Makefile
                src/java/util/Makefile
                src/org/xml/sax/Makefile
                src/org/xml/sax/helpers/Makefile
                src/javax/xml/parsers/Makefile
                tests/Makefile])
AC_OUTPUT

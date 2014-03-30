TESTS = besttest.sh
check_PROGRAMS = simple_tester
simple_tester_SOURCES = SimpleTester.cpp SimpleTester.hpp
simple_tester_CXXFLAGS = -g -I$(top_srcdir)/src

AM_LDFLAGS = -L$(top_builddir)/.libs -lexpat -lbestofjava

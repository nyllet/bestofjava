## Place generated object files (.o) into the same directory as their source
## files, in order to avoid collisions when non-recursive make is used.
AUTOMAKE_OPTIONS = subdir-objects

SUBDIRS = src tests
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libbestofjava.la
libbestofjava_la_SOURCES = src/java/util/Calendar.cpp \
			src/java/util/Properties.cpp \
			src/java/io/OutputStreamWriter.cpp \
			src/java/io/OutputStream.cpp \
			src/java/io/PrintWriter.cpp \
			src/java/io/File.cpp \
			src/java/io/IOException.cpp \
			src/java/io/Writer.cpp \
			src/java/lang/System.cpp \
			src/java/net/URLDecoder.cpp \
			src/org/xml/sax/helpers/DefaultHandler.cpp \
			src/org/xml/sax/Attributes.cpp \
			src/org/xml/sax/SAXException.cpp \
			src/javax/xml/parsers/SAXParserFactory.cpp \
			src/javax/xml/parsers/SAXParser.cpp

libbestofjava_la_CXXFLAGS = \
	-I$(top_srcdir)/src \
	-Weffc++ -Wall -Wextra -Werror -Wcast-align -Wcast-qual -Wconversion -Wdisabled-optimization -Wfloat-equal -Wformat=2 -Wmissing-format-attribute -Wmissing-noreturn -Wno-deprecated-declarations -Wno-format-y2k -Wno-format-extra-args -Wold-style-cast -Wpacked -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-compare -Wundef

libbestofjava_la_LDFLAGS = -version-info 0:0:0

## Define an independent executable script for inclusion in the distribution
## archive. However, it will not be installed on an end user's system due to
## the noinst_ prefix.
dist_noinst_SCRIPTS = autogen.sh

EXTRA_DIST = 	README.md
		tests/besttest.sh \
		tests/SimpleTester.cpp \
		tests/SimpleTester.hpp \
		tests/SimpleTester.java


MAINTAINERCLEANFILES = \
	Makefile.in \
	aclocal.m4 \
	configure \
	config.guess \
	config.sub \
	depcomp \
	install-sh \
	ltmain.sh \
	missing \
	compile

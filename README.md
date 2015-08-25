# bestofjava #

the best pieces of java available as a plain c++ library

Copyright (C) 2014,2015 Martin Nylin <https://github.com/nyllet>

This program is free software; you may redistribute it under the
terms of the GNU General Public License.  This program has absolutely
no warranty.  See the file COPYING for details.

## Raison d'être ##
This small project started out a couple of years ago as a collection of classes and methods of things that the author perceived as more elegantly implemented in java than in c++. One such thing is to encapsulate platform dependent code. Another thing is to provide methods for things that can be done with a simple one liner in java, but takes a lot of typing to get the job done in c++, such as get the current time in milliseconds for instance. The biggest block of code in the libarary right now is the SAXParser which is based on expat.

## Statement of compliance ##
This library aims to provide an API which is reasonably similar to the OpenJDK reference implemenatation of java version 1.8.

## INSTALLATION ##
all the details are described in the INSTALL file, but as of now the INSTALL file does not tell the whole truth: there is no configure file in this repo. Fortunately, you may generate it easily yourself like this:

1. make sure aclocal, autoheader, libtoolize, autoconf, automake and other dependencies are installed before you proceed. On a debian based system it is as simple as just

        sudo apt-get install automake libtool autoconf-archive libexpat1-dev make

2. mkdir m4
3. aclocal
4. autoheader
5. libtoolize
6. autoconf
7. automake --add-missing

and then continue with the usual

    ./configure && make && sudo make install.

### Dependencies ##
expat - http://www.libexpat.org

## Home Page ##
https://github.com/nyllet/bestofjava

## BUG REPORTING AND FEATURE REQUESTS ##
please see this issue tracker: https://github.com/nyllet/bestofjava/issues

## EXAMPLES ##
See the SimpleTester class in the tests directory to get a grip of how this library can be used. Some time in the future there will be better examples provided.

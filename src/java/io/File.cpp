/* An abstract representation of file and directory pathnames. 
   Copyright (C) 2014 Martin Nylin

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
#include "File.hpp"
#include <sys/stat.h>
#include <unistd.h>
#include <ctime>
#include <string>

namespace bestofjava {

   File::File(const std::string& pathname) : myPathName(pathname) {
   }

   File::~File() {
   }

   bool File::exists() const {
      struct stat filestat;
      if (stat(myPathName.c_str(), &filestat )) return false; //error during stat
      return true;
   }
   
   std::string File::getName() const {
      return myPathName;
   }

   bool File::isDirectory() {
      struct stat filestat;
      if (stat(myPathName.c_str(), &filestat )) return false; //error during stat
      if (S_ISDIR( filestat.st_mode )) return true;
      return false;
   }


   /**
    *     Returns the time that the file denoted by this abstract pathname was last modified.
    *
    *     Returns:
    *       A long value representing the time the file was last modified, measured in milliseconds
    *       since the epoch (00:00:00 GMT, January 1, 1970), or 0L if the file does not exist or if
    *       an I/O error occurs
    */
   long long File::lastModified() {
      struct stat64 attrib;			// create a file attribute structure
      stat64(myPathName.c_str(), &attrib);		// get the attributes of afile.txt
      return (static_cast<long long>(1000))*attrib.st_mtime;
   }

} // namespace bestofjava

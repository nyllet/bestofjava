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

   std::string File::getAbsolutePath() const {
      if (myPathName.at(0) == '/') return myPathName;
      return std::string(getcwd(nullptr,0)).append("/").append(myPathName);
   }
   
   std::string File::getName() const {
      size_t lastSlash = myPathName.find_last_of('/');
      if (lastSlash == std::string::npos) return myPathName;
      return myPathName.substr(lastSlash + 1);
   }

   std::string File::getParent() const {
      size_t lastSlash = myPathName.find_last_of('/');
      if (lastSlash != std::string::npos) 
         return myPathName.substr(0,lastSlash);
      return std::string(getcwd(nullptr,0));

   }

   bool File::isDirectory() const {
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
   uint64_t File::lastModified() {
      struct stat64 attrib;			// create a file attribute structure
      if (stat64(myPathName.c_str(), &attrib) == 0) {		// get the attributes of myPathName
         return (static_cast<uint64_t>(1000))*attrib.st_mtime;
      } else  {
         perror("error in File::lastModified()");
         return 0;
      }
   }

} // namespace bestofjava

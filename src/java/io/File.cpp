/* An abstract representation of file and directory pathnames. 
   Copyright (C) 2014,2015 Martin Nylin

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
#include <chrono>
#include <cstdint>
#include <system_error>
#include <string>

namespace bestofjava {

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__)
   constexpr std::string File::separator("\\"); //will this work for msdos and others? maybe not....
#else
   constexpr std::string File::separator("/");
#endif


   File::File(std::string pathname) : myPathName(std::move(pathname)) {
   }

   [[nodiscard]] bool File::exists() const noexcept {
      return std::filesystem::exists(myPathName);
   }

   [[nodiscard]] std::string File::getAbsolutePath() const {
        return std::filesystem::absolute(myPathName).string();
    }

   [[nodiscard]] std::string File::getName() const {
      return myPathName.filename().string();
   }

   [[nodiscard]] std::string File::getParent() const {
      if (auto parent = myPathName.parent_path(); !parent.empty()) {
         return parent.string();
      }
      return {}; // return empty if no parent exists
   }

   [[nodiscard]] bool File::isDirectory() const noexcept {
        return std::filesystem::is_directory(myPathName);
    }



   /**
    *     Returns the time that the file denoted by this abstract pathname was last modified.
    *
    *     Returns:
    *       A long value representing the time the file was last modified, measured in milliseconds
    *       since the epoch (00:00:00 GMT, January 1, 1970), or 0L if the file does not exist or if
    *       an I/O error occurs
    */
   [[nodiscard]] uint64_t File::lastModified() const noexcept {
      std::error_code ec;  // don’t throw on error
      auto ftime = std::filesystem::last_write_time(myPathName, ec);

      if (ec) {
/*
         std::cerr << "error in File::lastModified() while accessing "
                   << myPathName << ": " << ec.message() << '\n';
*/
         return 0;
      }

      // Convert filesystem time_point → system_clock → ms since epoch
      auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
         ftime - decltype(ftime)::clock::now() + std::chrono::system_clock::now()
         );

      auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
         sctp.time_since_epoch()
         ).count();

      return static_cast<uint64_t>(ms + 1);
   }



} // namespace bestofjava

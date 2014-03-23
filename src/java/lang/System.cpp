/* The System class contains several useful class fields and methods. It cannot be instantiated. 
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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include "System.hpp"

namespace bestofjava {

   /**
    * Returns the current time in milliseconds. Note that while the unit of time of the return value is a millisecond, the granularity of the value depends on the underlying operating system and may be larger. For example, many operating systems measure time in units of tens of milliseconds. */
   long long System::currentTimeMillis() {
      struct timeval tv;
      struct timezone tz;
      int res = gettimeofday(&tv, &tz); 
      if (res != 0) {
         std::cerr << "gettimeofday returned " << res << std::endl;
         return res; // res is -1 in this case
      }
      struct tm *mtm;
      struct tm timeInfo;
      mtm = localtime_r(&tv.tv_sec,&timeInfo);
      char eposecs[32];
      strftime(eposecs, sizeof(eposecs), "%s", mtm);
      char result[14];
      snprintf(result, sizeof(result), "%ld%03ld\n",atol(eposecs), static_cast<long>(tv.tv_usec)/static_cast<long>(1000));
      return atol(result);
   }
} // namespace bestofjava

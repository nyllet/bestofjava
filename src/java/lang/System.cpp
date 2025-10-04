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

#include <chrono>
#include "System.hpp"

namespace bestofjava {

   /**
    * Returns the current time in milliseconds. Note that while the unit of time of the return value is a millisecond, the granularity of the value depends on the underlying operating system and may be larger. For example, many operating systems measure time in units of tens of milliseconds. */
   uint64_t System::currentTimeMillis() {
      std::chrono::time_point<std::chrono::system_clock> my_now = std::chrono::system_clock::now();
      auto duration =my_now.time_since_epoch();
      return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
   }

/**
 * Determines the current system properties.
 */
   Properties System::getProperties() {
      return Properties();
   }

} // namespace bestofjava

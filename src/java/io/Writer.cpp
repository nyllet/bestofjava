/* Abstract class for writing to character streams.
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

#include "Writer.hpp"
#include <string>

namespace bestofjava {

   void Writer::write(const char* cbuf) {
      std::string str(cbuf);
      write(cbuf, 0, str.length());
   }

/**
 * Writes a string
 */
   void Writer::write(const std::string& str) {
      write(str.c_str(), 0, str.length());
   }

} // namespace bestofjava

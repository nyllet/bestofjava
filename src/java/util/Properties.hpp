/* The Properties class represents a persistent set of properties. The Properties can be saved to a stream or loaded from a stream. Each key and its corresponding value in the property list is a string.
   A property list can contain another property list as its "defaults"; this second property list is searched if the property key is not found in the original property list. 
   Copyright (C) 2017 Martin Nylin

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

#ifndef UTIL_PROPERTIES
#define UTIL_PROPERTIES

#include <string>
#include <unordered_map>
#include <utility>

namespace bestofjava {

   class Properties : public std::unordered_map<std::string, std::string> {
   public:
      std::string getProperty(const std::string& key) const;
      void setProperty(const std::string& key, const std::string& value); //TODO return something?
   
   };

} // namespace bestofjava

#endif

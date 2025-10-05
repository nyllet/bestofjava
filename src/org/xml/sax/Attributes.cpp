/* Interface for a list of XML attributes.
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

#include "Attributes.hpp"
#include <string>


namespace bestofjava {

   Attributes::Attributes(const XML_Char ** atts) : myAtts() {
      if (!atts) {
         return;
      }
      for (const XML_Char** p = atts; *p != nullptr && *(p + 1) != nullptr; p += 2) {
         myAtts.emplace_back(*p, *(p + 1));  // name/value pair
      }
   }
   
   [[nodiscard]] std::size_t Attributes::getLength() const noexcept {
      return myAtts.size();
   }

   [[nodiscard]] const std::string& Attributes::getQName(std::size_t i) const {
      if (i >= myAtts.size()) {
         static const std::string empty;
         return empty;
      }
      return myAtts[i].first;
   }
   
   [[nodiscard]] const std::string& Attributes::getValue(std::size_t i) const {
      if (i >= myAtts.size()) {
         static const std::string empty;
         return empty;
      }
      return myAtts[i].second;
   }

   [[nodiscard]] std::string Attributes::getValue(const std::string& qName) const {
      for (const auto& [name, value] : myAtts) {
         if (name == qName) {
            return value;
         }
      }
      return {};
   }


} // namespace bestofjava

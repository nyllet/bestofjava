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

   Attributes::Attributes(const XML_Char ** atts) :  myAtts(atts) {
      
   }
   
   std::string Attributes::getQName(int i) const {
      for(int j=0; j <= i && myAtts[j] != nullptr; j++)
         if (j==i) return myAtts[j];
      return "";
   }


   
   int Attributes::getLength() const {
      int i=0;
      while(myAtts[i] != nullptr)
         i++;
      return i;
   }

} // namespace bestofjava

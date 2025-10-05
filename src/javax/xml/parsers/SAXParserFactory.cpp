/* Defines a factory API that enables applications to configure and
   obtain a SAX based parser to parse XML documents. 
   Copyright (C) 2013 Martin Nylin

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

#include "SAXParserFactory.hpp"

namespace bestofjava {

   SAXParserFactory SAXParserFactory::newInstance() {
      return {};
   }
   
   SAXParser SAXParserFactory::newSAXParser() {
      return {};
   }
} // namespace bestofjava

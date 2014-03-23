/* Defines the API that wraps an XMLReader implementation class. 
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

#ifndef SAXPARSER_H
#define SAXPARSER_H

#include "org/xml/sax/helpers/DefaultHandler.hpp"
#include "java/io/File.hpp"


typedef struct {
   bestofjava::DefaultHandler* dh;
   std::string last_content;
} PContext;

namespace bestofjava {
   
   class SAXParser {
      
   public:
      SAXParser(); 
      SAXParser(const SAXParser&);
      SAXParser& operator=(const SAXParser&);
      ~SAXParser();
      void parse(const File&,  DefaultHandler&); // TODO(nyllet): DefaultHandler should be const
      
   private:
      PContext ctxt;
   };

} // namespace bestofjava

#endif

/* Receive notification of the logical content of a document. 
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

#ifndef CONTENTHANDLER_H
#define CONTENTHANDLER_H


#include <string>
#include "org/xml/sax/Attributes.hpp"

namespace bestofjava {

   class ContentHandler {
   public:
      virtual ~ContentHandler(){}
      /** Receive notification of the beginning of a document. */
      virtual void startDocument() = 0;
      /** Receive notification of the end of a document. */
      virtual void endDocument() = 0;
      /** Receive notification of the beginning of an element. */
      virtual void startElement(const std::string& uri,const std::string& localname, const std::string&   qname, const Attributes& attrs)= 0;
      /** Receive notification of character data. */
      virtual void characters(const std::string&) = 0;
      /** Receive notification of the end of an element. */
      virtual void endElement(const std::string& uri, const std::string& localname,const std::string& qname)= 0;
      
   };


} // namespace bestofjava

#endif

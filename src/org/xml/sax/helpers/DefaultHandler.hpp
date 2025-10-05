/* Default base class for SAX2 event handlers. 
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

#ifndef DEFAULTHANDLER_H
#define DEFAULTHANDLER_H

#include <string>
#include "org/xml/sax/ContentHandler.hpp"

namespace bestofjava {
   class Attributes;

   class DefaultHandler : public ContentHandler {
      
   public:
      DefaultHandler() = default;
      ~DefaultHandler() override = default;
      /** By default, do nothing. */
      void startDocument() override;
      /** By default, do nothing. */
      void endDocument() override;
      /** By default, do nothing. */
      void startElement(const std::string& uri,const std::string& localname, const std::string& qname, const Attributes& attrs) override = 0;
      /** By default, do nothing. */
      void characters(const std::string&) override = 0;
      /** By default, do nothing. */
      void endElement(const std::string& uri, const std::string& localname,const std::string& qname) override = 0;
      static void startElement_callback(DefaultHandler*,const std::string&,const std::string&,const std::string& , const Attributes&);
      static void endElement_callback(DefaultHandler*,const std::string&,const std::string&,const std::string&);
      static void characters_callback(DefaultHandler*,const std::string& chars);
      static void startDocument_callback(DefaultHandler* dh);
      static void endDocument_callback(DefaultHandler* dh);
   };

} // namespace bestofjava
   
#endif

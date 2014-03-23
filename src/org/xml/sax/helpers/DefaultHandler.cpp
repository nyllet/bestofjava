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

#include "DefaultHandler.hpp"
#include <cassert>
#include <string>

namespace bestofjava {

   DefaultHandler::DefaultHandler() {
   }
   
   DefaultHandler::~DefaultHandler() {
   }

   void DefaultHandler::startDocument() {
   }
   
   void DefaultHandler::endDocument(){
   }

    
   void DefaultHandler::startElement_callback(DefaultHandler* dh,const std::string& uri,const std::string& localname,const std::string& qname, const Attributes& atts){
      dh->startElement(uri,localname,qname,atts);
   }
   
   void DefaultHandler::endElement_callback(DefaultHandler* dh,const std::string& uri,const std::string& localname,const std::string& qname){
      dh->endElement(uri,localname,qname);
   }
   
   void DefaultHandler::characters_callback(DefaultHandler* dh,const std::string& chars) {
      assert(dh != nullptr);
      dh->characters(chars);
   }
   
   
   void DefaultHandler::startDocument_callback(DefaultHandler* dh) {
      dh->startDocument();
   }
   
   void DefaultHandler::endDocument_callback(DefaultHandler* dh) {
      dh->endDocument();
   }

} // namespace bestofjava

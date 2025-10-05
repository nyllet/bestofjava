
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

#include "org/xml/sax/Attributes.hpp"
#include "org/xml/sax/helpers/DefaultHandler.hpp"
#include "org/xml/sax/SAXException.hpp"
#include "java/io/File.hpp"
#include "java/io/IOException.hpp"
#include "SAXParser.hpp"
#include <expat.h>
#include <cassert>
#include <string>

// cppcheck suggests that encodingHandlerData and info could be pointers to const. In fact they can not since the callback signature must match Expat’s XML_UnknownEncodingHandler typedef
// cppcheck-suppress constParameterCallback
int XMLCALL unknownEncodingHandler(void* encodingHandlerData __attribute__((__unused__)), const XML_Char *name __attribute__((__unused__)), XML_Encoding *info __attribute__((__unused__))) {
   return XML_STATUS_ERROR;
}

/* callback for start element, e.g. <tag> */
void XMLCALL startElementCallback(void *context, const XML_Char *qname, const XML_Char **atts ){
   PContext *ctxt = static_cast<PContext*>(context);
   if (!ctxt->last_content.empty()) {
      assert(ctxt->dh != nullptr);
      bestofjava::DefaultHandler::characters_callback(ctxt->dh, ctxt->last_content);
      ctxt->last_content = "";
   }
   bestofjava::DefaultHandler::startElement_callback(ctxt->dh,std::string(""),std::string(""),std::string(qname),  bestofjava::Attributes(atts));
   ctxt->last_content = "";
}
 
/* callback for end elements, e.g. </tag>,
 * it is called for empty elements, too
 */
void XMLCALL endElementCallback( void *context,const XML_Char *name __attribute__((__unused__)) ) {
   PContext *ctxt = static_cast<PContext*>(context);
   if (ctxt->last_content.find_last_not_of(" \n\r\t") != std::string::npos) {
      bestofjava::DefaultHandler::characters_callback(ctxt->dh, ctxt->last_content);
   }
   ctxt->last_content = "";
   bestofjava::DefaultHandler::endElement_callback(ctxt->dh,std::string(""), std::string(""), std::string(name));
}


void handle_data(void *context, const char *content, int length) {
   PContext *ctxt = static_cast<PContext*>(context);
   if (length >0 && content != nullptr) {
      ctxt->last_content.append(content, static_cast<size_t>(length));
   }
}


namespace bestofjava {

   void SAXParser::parse(const File& xmlfile, DefaultHandler* dh) { //throws IOException, SAXException
      ctxt.dh = dh;
      std::FILE* docfd = std::fopen(xmlfile.getAbsolutePath().c_str(), "r");
      if (docfd == nullptr) {
         throw IOException(std::string("SAXParser::parse failed to open ").append(xmlfile.getAbsolutePath()).append(" for parsing."));
      }
      constexpr int BUFF_SIZE = 255;
      XML_Parser parser = XML_ParserCreate(nullptr);
/* Create parser.
 * The only argument for XML_ParserCreate is encoding, and if it's nullptr,
 * then encoding declared in the document is used. Expat supports natively
 * US-ASCII, UTF-8, UTF-16, and ISO-8859-1. If any other encoding is
 * detected, expat calls UnknownEncodingHandler().
 */
      if (parser) {
/* set callback for unknown encoding */
         XML_SetUnknownEncodingHandler(parser, &unknownEncodingHandler, nullptr);
         XML_SetUserData(parser, &ctxt);
/* set callback for start element */
         XML_SetStartElementHandler(parser, &startElementCallback);
/* set callback for start element */
         XML_SetEndElementHandler(parser, &endElementCallback);
         XML_SetCharacterDataHandler(parser, handle_data);
      } else {
         std::string error_msg("Failed to create XML_Parser for ");
         error_msg.append(xmlfile.getName());
         if (std::fclose(docfd) != 0) {
            error_msg.append(". And on top of that closing the file also failed");
         }
         throw SAXException(error_msg);
      }
      
      // XML_ParsingStatus myStatus;
      // XML_GetParsingStatus(parser, &myStatus);
      // if (myStatus.parsing == XML_FINISHED) XML_ParserReset(parser, nullptr); 
      DefaultHandler::startDocument_callback(dh);
      std::string error_msg;
      for (;;) {
         void* buff = XML_GetBuffer(parser, BUFF_SIZE);

         if (buff == nullptr) {
            error_msg = std::string("SAXParser::parse error: XML_GetBuffer returned nullptr while parsing ").append(xmlfile.getAbsolutePath()).append(", error = ").append(std::to_string(XML_GetErrorCode(parser))).append(". meaning ").append(XML_ErrorString(XML_GetErrorCode(parser)));
            break;
         } 
         
         const std::size_t bytes_read = std::fread(buff, 1, static_cast<size_t>(BUFF_SIZE), docfd);

         if (bytes_read == 0) {
            if (std::feof(docfd)) {
               break;     // normal EOF
            }
         }
         if (std::ferror(docfd)) {        // read error
            error_msg = "SAXParser::parse error: fread failed on " + xmlfile.getAbsolutePath();
            break;
         }
      
         if (! XML_ParseBuffer(parser, static_cast<int>(bytes_read), bytes_read == 0)) {
            error_msg = std::string("SAXParser::parse error: XML_ParseBuffer failed while parsing ").append(xmlfile.getAbsolutePath());
            break;
         }
         if (std::feof(docfd)) {
            break;     // normal EOF
         }
      }
      if (error_msg.empty()) {
         DefaultHandler::endDocument_callback(dh);
      }
/* Free resource used by expat */
      XML_ParserFree(parser);
      if ((std::fclose(docfd) != 0) && !error_msg.empty()) {
         error_msg.append(". And on top of that closing the file also failed");
      }
      if (!error_msg.empty()) {
         throw SAXException(error_msg);
      }
   }

   SAXParser::SAXParser() : ctxt{nullptr, ""} {
   
   }

} // namespace bestofjava

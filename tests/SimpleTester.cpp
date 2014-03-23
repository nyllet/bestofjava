/* This hack is used to perform some simple tests such as parse an xml file and
   make some printouts that may be compared with those of a similar java test
   program. 
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

#include <fstream>
#include <iostream>
#include <string>
#include "SimpleTester.hpp"
#include "javax/xml/parsers/SAXParserFactory.hpp"
#include "java/io/PrintWriter.hpp"
#include "java/lang/System.hpp"
/*
 * When the parser encounters plain text (not XML elements),
 * it calls(this method, which accumulates them in a string buffer
 */
void SimpleTester::characters(const std::string& chars) {
   temp.append(chars);
}
      

/*
 * Every time the parser encounters the beginning of a new element,
 * it calls this method, which resets the string buffer
 */ 
void SimpleTester::startElement(const std::string& uri,
                                             const std::string& localName,
                                             const std::string& qName,
                                             const bestofjava::Attributes& attributes)  {
   temp = "";
   std::cout << "<" << qName << ">";
   if (!uri.empty()) std::cout << "uri: " << uri << " ";
   if (!localName.empty()) std::cout << "localName: " << localName << " ";
}

/*
 * When the parser encounters the end of an element, it calls this method
 */
void SimpleTester::endElement(const std::string&    uri,
                                           const std::string&   localName,
                                           const std::string&   qName) {
   if (!uri.empty()) std::cout << "uri: " << uri << " ";
   if (!localName.empty()) std::cout << "localName: " << localName << " ";
   if (!temp.empty()) std::cout << "characters: " << temp;
   std::cout << "</" << qName << ">" << std::endl;
}


int main(int argc, char **argv) {
   std::ofstream myfile;
   myfile.open ("/tmp/bestofjava/cpp_time.txt");
   myfile << bestofjava::System::currentTimeMillis() << std::endl;
   myfile.close();
   
   //Create a "parser factory" for creating SAX parsers
   bestofjava::SAXParserFactory spfac = bestofjava::SAXParserFactory::newInstance();
   
   //Now use the parser factory to create a SAXParser object
   bestofjava::SAXParser sp = spfac.newSAXParser();
   
   //Create an instance of this class; it defines all the handler methods
   SimpleTester handler;
   
   //Finally, tell the parser to parse the input and notify the handler
   bestofjava::File myFile(argv[1]);
   sp.parse(myFile, handler);
   std::cout << myFile.getName() << " was last modified " << myFile.lastModified() << std::endl;
}





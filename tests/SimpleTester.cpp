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
#include "java/util/Calendar.hpp"

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
   std::cout << myFile.getAbsolutePath() << " was last modified " << myFile.lastModified() << std::endl;
   bestofjava::Calendar fileCalendar;
   fileCalendar.setTimeInMillis(myFile.lastModified());
   std::cout << "which means year: " << fileCalendar.get(bestofjava::Calendar::YEAR) << ", month: " << fileCalendar.get(bestofjava::Calendar::MONTH) << ", date: " << fileCalendar.get(bestofjava::Calendar::DAY_OF_MONTH) << ", hour: " << fileCalendar.get(bestofjava::Calendar::HOUR_OF_DAY) << ", minute: " << fileCalendar.get(bestofjava::Calendar::MINUTE) << ", second: " << fileCalendar.get(bestofjava::Calendar::SECOND) << std::endl;
   bestofjava::Calendar oldCal,newCal;
   if (myFile.exists()) std::cout << "oh yes, " << myFile.getName() << " exists" << std::endl;
   else std::cout << "crap, " << myFile.getName() << " does not exist" << std::endl;
   std::cout << "the absolute path is " << myFile.getAbsolutePath() << std::endl;
   std::cout << "the parent dir is " + myFile.getParent() << std::endl;
   bestofjava::File parentDir(myFile.getParent());
   if (parentDir.isDirectory()) std::cout << parentDir.getAbsolutePath() << " is a directory" << std::endl;
   else std::cout << parentDir.getAbsolutePath() << " is not a directory" << std::endl;
   oldCal.setTimeInMillis(myFile.lastModified());
   newCal.setTimeInMillis(bestofjava::System::currentTimeMillis());
   if (oldCal.after(newCal)) std::cout << "oups, " << oldCal.getTimeInMillis() << " is after " << newCal.getTimeInMillis() << std::endl;
   if (newCal.before(oldCal)) std::cout << "oups, " << newCal.getTimeInMillis() << " is before " << oldCal.getTimeInMillis() << std::endl;
   // bestofjava::Calendar getset;
   // int year=2014, month=4, day_of_month=5;
   // getset.set(year, month, day_of_month);
   // std::cout << "2014-04-05 in millis: " << getset.getTimeInMillis() << std::endl;
   // std::cout << "year: " << getset.get(bestofjava::Calendar::YEAR) << ", month: " << getset.get(bestofjava::Calendar::MONTH) << ", date: " << getset.get(bestofjava::Calendar::DAY_OF_MONTH) << ", hour: " << getset.get(bestofjava::Calendar::HOUR_OF_DAY) << ", minute: " << getset.get(bestofjava::Calendar::MINUTE) << ", second: " << getset.get(bestofjava::Calendar::SECOND) << std::endl;
   // getset.setTimeInMillis(getset.getTimeInMillis());
   // std::cout << "after calendar time is reset in millis: year: " << getset.get(bestofjava::Calendar::YEAR) << ", month: " << getset.get(bestofjava::Calendar::MONTH) << ", date: " << getset.get(bestofjava::Calendar::DAY_OF_MONTH) << ", hour: " << getset.get(bestofjava::Calendar::HOUR_OF_DAY) << ", minute: " << getset.get(bestofjava::Calendar::MINUTE) << ", second: " << getset.get(bestofjava::Calendar::SECOND) << std::endl;
   
   
   
}





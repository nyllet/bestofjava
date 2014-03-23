/* Prints formatted representations of objects to a text-output stream.
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

#include "PrintWriter.hpp"
#include <string>

namespace bestofjava {

   PrintWriter::PrintWriter(OutputStream* out) : myOutputStream(out) {
   }

   PrintWriter& PrintWriter::operator=(const PrintWriter& pw) {
      if (this == &pw)
         return *this;
      this->myOutputStream = pw.myOutputStream;
      return *this;
   }

   PrintWriter::~PrintWriter() {
   }

   void PrintWriter::close(){
      myOutputStream->close();
   }

   void PrintWriter::flush(){
      myOutputStream->flush();
   }

   void PrintWriter::print(const char* str) const {
      myOutputStream->write(str);
   }

   void PrintWriter::println(const char* str) const {
      myOutputStream->write(str);
      *myOutputStream << std::endl;
   }

   void PrintWriter::print(std::string* str) const {
      if (str == nullptr) return;
      myOutputStream->write(str->c_str());
   }

   void PrintWriter::print(const std::string& str) const {
   
      myOutputStream->write(str.c_str());
   }

/**
 * Prints a double-precision floating-point number.
 */
   void PrintWriter::print(double d) const {
      myOutputStream->write(std::to_string(d).c_str());
   }

   void PrintWriter::print(int i) const {
      myOutputStream->write(std::to_string(i).c_str());
   }

   void PrintWriter::print(long long l) const {
      myOutputStream->write(std::to_string(l).c_str());
   }

   void PrintWriter::print(unsigned int i) const {
      myOutputStream->write(std::to_string(i).c_str());
   }


/**
 * Prints a double-precision floating-point number and then terminates the line.
 */
   void PrintWriter::println(double d) const {
      myOutputStream->write(std::to_string(d).c_str());
      *myOutputStream << std::endl;
   }


   void PrintWriter::println(std::string* str) const {
      myOutputStream->write(str->c_str());
      *myOutputStream << std::endl;
   }

   void PrintWriter::println(const std::string& str) const {
      myOutputStream->write(str.c_str());
      *myOutputStream << std::endl;
   }

   void PrintWriter::write(const char* buf, int off, int len) {
      std::string tmpstr(buf);
      print(tmpstr.substr(off,len));
   }

} // namespace bestofjava

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

#include "java/io/OutputStream.hpp"
#include "PrintWriter.hpp"
#include <string>

namespace bestofjava {

   PrintWriter::PrintWriter(OutputStream* out) : myOutputStream(out), myWriter(nullptr) {
   }

   PrintWriter::PrintWriter(Writer* out) : myOutputStream(nullptr), myWriter(out) {
   }

   PrintWriter& PrintWriter::operator=(const PrintWriter& pw) {
      if (this == &pw)
         return *this;
      this->myOutputStream = pw.myOutputStream;
      this->myWriter = pw.myWriter;
      return *this;
   }

   PrintWriter::~PrintWriter() {
   }

   void PrintWriter::close(){
      if (myOutputStream != nullptr) myOutputStream->close();
      else myWriter->close();
   }

   void PrintWriter::flush(){
      if (myOutputStream != nullptr) myOutputStream->flush();
      else myWriter->flush();
   }

   void PrintWriter::print(const char* str) const {
      if (myOutputStream != nullptr) myOutputStream->write(str);
      else myWriter->write(str);
   }

   void PrintWriter::println(const char* str) const {
      if (myOutputStream != nullptr) {
         myOutputStream->write(str);
         *myOutputStream << std::endl;
      } else {
         myWriter->write(std::string(str).append("\n"));
      }
   }

   void PrintWriter::print(std::string* str) const {
      if (str == nullptr) return;
      if (myOutputStream != nullptr) myOutputStream->write(str->c_str());
      else myWriter->write(*str);
   }

   void PrintWriter::print(const std::string& str) const {
      if (myOutputStream != nullptr) myOutputStream->write(str.c_str());
      else myWriter->write(str);
   }

/**
 * Prints a double-precision floating-point number.
 */
   void PrintWriter::print(double d) const {
      if (myOutputStream != nullptr) myOutputStream->write(std::to_string(d).c_str());
      else myWriter->write(std::to_string(d));
   }

   void PrintWriter::print(int i) const {
      if (myOutputStream != nullptr) myOutputStream->write(std::to_string(i).c_str());
      else myWriter->write(std::to_string(i));
   }

   void PrintWriter::print(int64_t l) const {
      if (myOutputStream != nullptr) myOutputStream->write(std::to_string(l).c_str());
      else myWriter->write(std::to_string(l));
   }

   void PrintWriter::print(uint64_t ul) const {
      if (myOutputStream != nullptr) myOutputStream->write(std::to_string(ul).c_str());
      else myWriter->write(std::to_string(ul));
   }

   void PrintWriter::print(unsigned int i) const {
      if (myOutputStream != nullptr) myOutputStream->write(std::to_string(i).c_str());
      else myWriter->write(std::to_string(i));
   }


/**
 * Prints a double-precision floating-point number and then terminates the line.
 */
   void PrintWriter::println(double d) const {
      if (myOutputStream != nullptr) {
         myOutputStream->write(std::to_string(d).c_str());
         *myOutputStream << std::endl;
      } else {
         myWriter->write(std::to_string(d).append("\n"));
      }
   }


   void PrintWriter::println(std::string* str) const {
      if (myOutputStream != nullptr) {
         myOutputStream->write(str->c_str());
         *myOutputStream << std::endl;
      } else {
         myWriter->write(str->append("\n"));
      }
   }

   void PrintWriter::println(const std::string& str) const {
      if (myOutputStream != nullptr) {
         myOutputStream->write(str.c_str());
         *myOutputStream << std::endl;
      } else {
         myWriter->write(std::string(str).append("\n"));
      }
   }

   void PrintWriter::write(const char* buf, size_t off, size_t len) {
      std::string tmpstr(buf);
      print(tmpstr.substr(off,len));
   }

} // namespace bestofjava

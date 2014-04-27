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

#ifndef PRINT_WRITER
#define PRINT_WRITER

#include <string>
#include "java/io/Writer.hpp"

class OutputStream;

namespace bestofjava {

   class PrintWriter : public Writer {
   public:
      explicit PrintWriter(OutputStream* os);
      explicit PrintWriter(Writer* out);
      PrintWriter(const PrintWriter& pw) : myOutputStream(pw.myOutputStream), myWriter(pw.myWriter) {}
      ~PrintWriter();
      PrintWriter& operator=(const PrintWriter&);
      void close();
      void flush();
      void print(const char*) const;
      void print(double d) const;
      void print(int i) const;
      void print(int64_t) const;
      void print(uint64_t) const;
      void print(std::string* s) const;
      void print(const std::string&) const;
      void print(unsigned int) const;
      void println(const char*) const;
      void println(double d) const;
      void println(std::string*) const;
      void println(const std::string&) const;
      void write(const char*, int , int);

   private:
      OutputStream* myOutputStream;
      Writer* myWriter;
   };

} // namespace bestofjava
   
#endif

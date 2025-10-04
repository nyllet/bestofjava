/* An OutputStreamWriter is a bridge from character streams to byte
   streams: Characters written to it are encoded into bytes using a
   specified charset. The charset that it uses may be specified by
   name or may be given explicitly, or the platform's default
   charset may be accepted. 
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

#include "OutputStream.hpp"
#include "OutputStreamWriter.hpp"
#include <string>

namespace bestofjava {

   OutputStreamWriter::OutputStreamWriter() : myOutputStream(nullptr), myOstream(nullptr) {
   }

   OutputStreamWriter::OutputStreamWriter(OutputStream* out) : myOutputStream(out), myOstream(nullptr) {
   }

   OutputStreamWriter::OutputStreamWriter(std::ostream* os) :  myOutputStream(nullptr), myOstream(os) {
   }

   void OutputStreamWriter::close() {
      if (myOutputStream != nullptr) myOutputStream->close();
   }

   void OutputStreamWriter::flush() {
      if (myOutputStream != nullptr) myOutputStream->flush();
      else if (myOstream != nullptr) myOstream->flush();
   }

   void OutputStreamWriter::setOstream(std::ostream* os) {
      if (myOutputStream != nullptr) myOutputStream->setOstream(os);
      else myOstream = os;
   }

   void OutputStreamWriter::write(const char* cbuf, size_t off, size_t len) {
      if (myOutputStream != nullptr) {
         myOutputStream->write(cbuf,off,len);
         return;
      }
      if (myOstream != nullptr && off == 0) {
         myOstream->write(cbuf, len);
         return;
      }
      if (myOstream != nullptr && off > 0) {
         std::string s(cbuf);
         myOstream->write(s.substr(off,len).c_str(),len);
      }
   }
   
} // namespace bestofjava

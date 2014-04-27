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
#ifndef OUTPUT_STREAM_WRITER_H
#define OUTPUT_STREAM_WRITER_H

class OutputStream;
#include "Writer.hpp"

namespace bestofjava {

   class OutputStreamWriter : public Writer {
   public:
      OutputStreamWriter();
      explicit OutputStreamWriter(std::ostream*);
      explicit OutputStreamWriter(OutputStream* os);
      virtual void close();
      virtual void flush();
      void setOstream(std::ostream*);
      virtual void write(const char*, int, int);
   protected:
      OutputStream* myOutputStream;
   private:
      OutputStreamWriter(const OutputStreamWriter&);
      OutputStreamWriter& operator=(const OutputStreamWriter&);
      std::ostream* myOstream;
   };

} // namespace bestofjava

#endif

/* This abstract class is the superclass of all classes representing
   an output stream of bytes. An output stream accepts output bytes
   and sends them to some sink. 
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
#ifndef OUTPUT_STREAM
#define OUTPUT_STREAM

#include <ostream>

namespace bestofjava {
   class OutputStream : public std::ostream {
   public:
      OutputStream();
      OutputStream(const OutputStream&);
      void close();
      void flush();
      void write(const char*, int, int);
      virtual void write(int b) = 0;
      void setOstream(std::ostream*);
      virtual void write(const std::string&) = 0;
      
   protected:
      std::ostream* myOstream;
      
   private:
      OutputStream& operator=(const OutputStream&);
   };

} // namespace bestofjava 

#endif

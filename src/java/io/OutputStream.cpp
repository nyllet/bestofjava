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
#include "OutputStream.hpp"
#include <string>

namespace bestofjava {
   OutputStream::OutputStream() : myOstream(nullptr) {
      
   }
   

   /**
    * The close method of OutputStream does nothing. 
    **/
   void OutputStream::close() {
   }
   
   /**
    * The flush method of OutputStream does nothing. 
    */
   void OutputStream::flush() {
   }

   /**
    * this method is a bit of a temporary solution. this is NOT the java way
    */
   void OutputStream::setOstream(std::ostream* os) {
      myOstream = os;
   }
   
   void OutputStream::write(const char* b,int off,int len) {
      std::string s(b);
      write(s.substr(off,len).c_str());
   }
   
} // namespace bestofjava


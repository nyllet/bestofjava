/* An abstract representation of file and directory pathnames.
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
#ifndef FILE_H
#define FILE_H

#include <string>

namespace bestofjava {

   class File {

   public:
      explicit File(const std::string&);
      ~File();
      std::string getAbsolutePath() const;
      std::string getName() const;
      bool exists() const;
      std::string getParent() const;
      bool isDirectory() const;
      int64_t lastModified();

   private:
      std::string myPathName;

   };

} // namespace bestofjava

#endif

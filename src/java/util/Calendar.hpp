/* The Calendar class is an abstract class that provides methods for
   converting between a specific instant in time and a set of calendar
   fields such as YEAR, MONTH, DAY_OF_MONTH, HOUR, and so on, and for
   manipulating the calendar fields, such as getting the date of the next week.
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
#ifndef CALENDAR
#define CALENDAR

#include <cstdint>
#include <cstdlib>
#include <ctime>
#include "java/lang/System.hpp"

namespace bestofjava {

   class Calendar {
   public:
      Calendar();
      static int DAY_OF_MONTH, DAY_OF_WEEK;
      static int MONTH,HOUR_OF_DAY,MINUTE,SECOND;
      static int YEAR, WEEK_OF_YEAR;
      static const int MONDAY=2,TUESDAY=3,WEDNESDAY=4,THURSDAY=5,FRIDAY=6,SATURDAY=7,SUNDAY=1;
      static const int JANUARY=0, FEBRUARY=1, MARCH=2, APRIL=3,MAY=4,JUNE=5,JULY=6,AUGUST=7,SEPTEMBER=8,OCTOBER=9,NOVEMBER=10,DECEMBER=11;
      bool after(Calendar when);
      bool before(Calendar when);
      int compareTo(Calendar anotherCalendar);
      int get(int i);
      uint64_t getTimeInMillis();
      void set(int year, int month, int date);
      void setTimeInMillis(uint64_t);
      
   private:
      uint64_t myTimeInMillis;
   };

} // namespace bestofjava

#endif

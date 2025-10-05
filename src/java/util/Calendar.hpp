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

namespace bestofjava {

   class Calendar {
   public:
      Calendar();
      static constexpr int DAY_OF_MONTH = 5, DAY_OF_WEEK = 7;
      static constexpr int MONTH = 2, HOUR_OF_DAY = 11, MINUTE=12, SECOND=13;
      static constexpr int YEAR = 1, WEEK_OF_YEAR=3;
      static constexpr int MONDAY=2, TUESDAY=3, WEDNESDAY=4, THURSDAY=5, FRIDAY=6, SATURDAY=7, SUNDAY=1;
      static constexpr int JANUARY=0, FEBRUARY=1, MARCH=2, APRIL=3, MAY=4, JUNE=5, JULY=6, AUGUST=7, SEPTEMBER=8, OCTOBER=9, NOVEMBER=10, DECEMBER=11;
      bool after(Calendar when) const;
      bool before(Calendar when) const;
      int compareTo(Calendar anotherCalendar) const;
      int get(int i) const;
      uint64_t getTimeInMillis() const;
      void set(int year, int month, int date);
      void setTimeInMillis(uint64_t);
      
   private:
      uint64_t myTimeInMillis;
   };

} // namespace bestofjava

#endif

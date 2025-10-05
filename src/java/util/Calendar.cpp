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

#include <sys/time.h>
#include <chrono>
#include <cstdlib> // for atoi
#include "Calendar.hpp"
#include "java/lang/System.hpp"

namespace bestofjava {

   Calendar::Calendar() : myTimeInMillis(0) {
   }

   /**
    * Returns whether this Calendar represents a time after the time represented by the specified Calendar.
    */
    bool Calendar::after(Calendar when) const {
      return compareTo(when) > 0;
   }

   /**
    * Returns whether this Calendar represents a time before the time represented by the specified Calendar.
    */
   bool Calendar::before(Calendar when) const {
      return compareTo(when) < 0;
   }

   int Calendar::compareTo(Calendar anotherCalendar) const {
      if (myTimeInMillis < anotherCalendar.getTimeInMillis()) {
         return -1;
      }
      if (myTimeInMillis > anotherCalendar.getTimeInMillis()) {
         return 1;
      }
      return 0;
   }


   int Calendar::get(int i) const { 
      time_t theTime;
      if (myTimeInMillis != 0) {
         theTime = static_cast<time_t>(myTimeInMillis / 1000);
      } else {
         theTime = static_cast<time_t>(System::currentTimeMillis() / 1000);   // get the current time
      }
      struct tm timeInfo;
      const struct tm *tmp = localtime_r(&theTime,&timeInfo);  // convert to local
      if (tmp == nullptr) {
         return -1; // localtime_r failure
      }

      switch (i) {
         case WEEK_OF_YEAR:
         {
            char res[3];
            if (strftime( res, sizeof(res), "%V", tmp ) == 0) {
               return -1;
            }
            return std::atoi(res);
         }
         case DAY_OF_MONTH:
         {
            char res[3];
            if (strftime( res, sizeof(res), "%d", tmp ) == 0) {
               return -1;
            }
            return std::atoi(res);
         }
         case DAY_OF_WEEK:
            switch (tmp->tm_wday) {
               case 0: return SUNDAY; // Sunday -> 7 in Java-style, but here we return SUNDAY
               case 1: return MONDAY;
               case 2: return TUESDAY;
               case 3: return WEDNESDAY;
               case 4: return THURSDAY;
               case 5: return FRIDAY;
               case 6: return SATURDAY;
               default: return -1;
            }
         case HOUR_OF_DAY:
         {
            char res[3];
            if (strftime( res, sizeof(res), "%H", tmp ) == 0) {
               return -1;
            }
            return std::atoi(res);
         }
         case MINUTE:
         {
            char res[3];
            if (strftime( res, sizeof(res), "%M", tmp ) == 0) {
               return -1;
            }
            return std::atoi(res);
         }
         case MONTH:
         {
            char res[3];
            if (strftime( res, sizeof(res), "%m", tmp ) == 0) {
               return -1;
            }
            return std::atoi(res) - 1;
         }
         case SECOND:
         {
            char res[3];
            if (strftime( res, sizeof(res), "%S", tmp ) == 0) {
               return -1;
            }
            return std::atoi(res);
         }
         case YEAR:
         {
            char res[5];
            if (strftime( res, sizeof(res), "%Y", tmp ) == 0) {
               return -1;
            }
            return std::atoi(res);
         }
         default:
            return -1;
      }
   }

   uint64_t Calendar::getTimeInMillis() const {
      return myTimeInMillis;
   }

   /**
    * Sets the values for the calendar fields YEAR, MONTH, and DAY_OF_MONTH. Previous values of other calendar fields are retained. If this is not desired, call clear() first.
    *
    * Parameters:
    * year - the value used to set the YEAR calendar field.
    * month - the value used to set the MONTH calendar field. Month value is 0-based. e.g., 0 for January.
    * date - the value used to set the DAY_OF_MONTH calendar field.
    */
   void Calendar::set(int year, int month, int date) {
      struct timeval tv;
      struct timezone tz;
      const int res = gettimeofday(&tv, &tz);
      if (res != 0) {
         return; 
      }
      std::tm timeInfoIn;
      std::tm * timeinfo = localtime_r(&tv.tv_sec,&timeInfoIn);
      timeinfo->tm_year = year - 1900;
      timeinfo->tm_mon = month;
      timeinfo->tm_mday = date;
      const std::time_t tt = timelocal(timeinfo);
      const std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(tt);
      auto this_time_since_epoch =tp.time_since_epoch();
      myTimeInMillis = static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(this_time_since_epoch).count());
   }
   
   void Calendar::setTimeInMillis(uint64_t millis) {
      myTimeInMillis = millis;
   }


} // namespace bestofjava

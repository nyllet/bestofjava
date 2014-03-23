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
#include "Calendar.hpp"

namespace bestofjava {

   int Calendar::YEAR = 1;
   int Calendar::MONTH = 2;
   int Calendar::WEEK_OF_YEAR = 3;
   int Calendar::DAY_OF_MONTH = 5;
   int Calendar::DAY_OF_WEEK = 7;
   int Calendar::HOUR_OF_DAY = 11;
   int Calendar::MINUTE = 12;
   int Calendar::SECOND = 13;


   Calendar::Calendar() : myTimeInMillis(-1) {
   }

   bool Calendar::after(Calendar when){
      return compareTo(when) > 0;
   }
   
   bool Calendar::before(Calendar when) {
      return compareTo(when) < 0;
   }

   int Calendar::compareTo(Calendar anotherCalendar) {
      if (myTimeInMillis < anotherCalendar.getTimeInMillis()) return -1;
      if (myTimeInMillis > anotherCalendar.getTimeInMillis()) return 1;
      return 0;
   }


   int Calendar::get(int i) { 
      time_t theTime;
      if (myTimeInMillis != -1) theTime = myTimeInMillis / 1000; 
      else theTime = System::currentTimeMillis() / 1000;   // get the current time
      struct tm timeInfo;
      struct tm *tmp = localtime_r(&theTime,&timeInfo);  // convert to local

      if (i == WEEK_OF_YEAR) {
         char res[3];
         if (strftime( res, sizeof(res), "%V", tmp ) == 0) return -1;
         return atoi(res);
      }
      if (i == DAY_OF_MONTH) {
         char res[3];
         if (strftime( res, sizeof(res), "%d", tmp ) == 0) return -1;
         return atoi(res);
      }
      if (i == DAY_OF_WEEK) {
         char res[2];
         switch (strftime( res, sizeof(res), "%u", tmp )) {
            case 1 : return MONDAY;
            case 2 : return TUESDAY;
            case 3 : return WEDNESDAY;
            case 4 : return THURSDAY;
            case 5 : return FRIDAY;
            case 6 : return SATURDAY;
            case 7 : return SUNDAY;
            default: return -1;
         }
      }
      if (i == HOUR_OF_DAY) {
         char res[3];
         if (strftime( res, sizeof(res), "%H", tmp ) == 0) return -1;
         return atoi(res);
      }
      if (i == MINUTE) {
         char res[3];
         if (strftime( res, sizeof(res), "%M", tmp ) == 0) return -1;
         return atoi(res);
      }
      if (i == MONTH) {
         char res[3];
         if (strftime( res, sizeof(res), "%m", tmp ) == 0) return -1;
         return atoi(res);
      }
      if (i == SECOND) {
         char res[3];
         if (strftime( res, sizeof(res), "%S", tmp ) == 0) return -1;
         return atoi(res);
      }

      if (i == YEAR) {
         char res[5];
         if (strftime( res, sizeof(res), "%Y", tmp ) == 0) return -1;
         return atoi(res);
      }

      return -1;
   }

   long long Calendar::getTimeInMillis() {
      return myTimeInMillis;
   }

   void Calendar::set(int year, int month, int day) {
/* get current timeinfo and modify it to the user's choice */
      time_t rawtime;
      time ( &rawtime );
      struct tm * timeinfo = localtime ( &rawtime );
      timeinfo->tm_year = year - 1900;
      timeinfo->tm_mon = month - 1;
      timeinfo->tm_mday = day;
      
      /* call mktime: timeinfo->tm_wday will be set */
      time_t theTime = mktime (timeinfo);
      myTimeInMillis = theTime * 1000;
   }
   
   void Calendar::setTimeInMillis(long long millis) {
      myTimeInMillis = millis;
   }


} // namespace bestofjava

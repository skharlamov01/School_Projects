/*Final Project Milestone 52
Module : Utility
Filename : Utils.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/07
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
   const int sdds_testYear = 2022;
   const int sdds_testMon = 03;
   const int sdds_testDay = 31;
   class Utils {
      bool m_testMode = false;
   public:
      // this function will be used to get the current system date or the test date if m_testMode is true
      void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
      // this function will return the number of days in a month based on the year
      // 1<=mon<=12  year: four digit number (example: 2021)
      int daysOfMon(int mon, int year)const;
      // Puts the system date in test mode, where getSystemDate() function will return 2022, 03, 31
      // or whatever the three constant test dates are set to
      void testMode(bool testmode = true);
      //Safely allocates memory in destination and copies the source into it.
      void alocpy(char*& destination, const char* source);
      //displays prompt (if prompt parameter not null) for user to enter integer
      //and does not exit until valid integer is entered
      int getint(const char* prompt = nullptr);
      //displays prompt (if prompt parameter not null) for user to enter integer
      //validates that integer is between min and max parameters
      // if errMes is not null, a simple message is displayed, otherwise a message showing min and max is displayed
      int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
      double getdouble(const char* prompt = nullptr);
      double getdouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
   };
   extern Utils ut; // provides global access to the ut instance in the Utils.cpp file
}

#endif // !SDDS_UTILS_H

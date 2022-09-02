/*Workshop 7 lab
Module : Utility
Filename : Utils.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/31
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
namespace sdds {
   class Utils {
   public:
      //Safely allocates memory in destination and copies the source into it.
      void alocpy(char*& destination, const char* source);
      //displays prompt (if prompt parameter not null) for user to enter integer
      //and does not exit until valid integer is entered
      int getint(const char* prompt = nullptr);
      //displays prompt (if prompt parameter not null) for user to enter integer
      //validates that integer is between min and max parameters
      // if errMes is not null, a simple message is displayed, otherwise a message showing min and max is displayed
      int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
      int getFileLength(std::istream& is);
   };
   extern Utils ut; // provides global access to the ut instance in the Utils.cpp file
}

#endif // !SDDS_UTILS_H

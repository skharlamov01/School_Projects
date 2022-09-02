/*Workshop 7 lab
Module : Utility
Filename : Utils.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/17
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  //using strlen in alocpy function
#include "Utils.h"
using namespace std;
namespace sdds {
   Utils ut;
   void Utils::alocpy(char*& destination, const char* source)
   {
       delete[] destination;
       destination = nullptr;
       if (source != nullptr) {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
   }
   int Utils::getint(const char* prompt)
   {
       int input = 0;
       bool valid = false;
       if (prompt != nullptr) {
           cout << prompt;
       }
       do {
           cin >> input;
           if (cin.fail()) {
               cout << "Invalid Integer, retry: ";
               cin.clear();
               cin.ignore(1000, '\n');
           }
           else
               valid = true;
       } while (!valid);
       return input;
   }
   int Utils::getint(int min, int max, const char* prompt, const char* errMes)
   {
       int input = 0;
       bool valid = false;
       if (prompt != nullptr) {
           cout << prompt;
       }
       do {
           input = getint();
           if (input >= min && input <= max) {
               valid = true;
           }
           else {
               if (errMes != nullptr) {
                   cout << errMes << ", retry: ";
               }
               else {
                   cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
               }
           }
       } while (!valid);
       return input;
   }
}
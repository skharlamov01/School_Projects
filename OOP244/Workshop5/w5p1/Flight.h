/* Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 16/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      bool loadPeople(int tpeople);
      /*type overloading*/
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;
      /*unary overloads*/
      bool operator~() const;
      /*binary overloads*/
      Flight& operator=(Flight& f);
      Flight& operator=(int passengers);
      Flight& operator=(double fuelcap);
      Flight& operator+=(double fuel);
      Flight& operator+=(int passengers);
      Flight& operator-=(double fuel);
      Flight& operator-=(int passengers);
      Flight& operator<<(Flight& f);
      Flight& operator>>(Flight& f);
   };
   int operator+(const Flight& f1, const Flight& f2);
   int operator+=(int& num, const Flight& f1);
}
#endif // SDDS_FLIGHT_H
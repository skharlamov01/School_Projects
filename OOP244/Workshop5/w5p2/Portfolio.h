/*Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 20/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void emptyPortfolio();
       void dispPortfolio() const;
       std::ostream& display() const;
       //conversions and operator overloads
       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       bool operator~() const;
       Portfolio& operator+=(double add);
       Portfolio& operator-=(double sub);
       Portfolio& operator<<(Portfolio& port2);
       Portfolio& operator>>(Portfolio& port2);
   };
   double operator+(const Portfolio& leftp, const Portfolio& rightp);
   double operator+=(double& add, const Portfolio& port1);
}
#endif // SDDS_Portfolio_H_
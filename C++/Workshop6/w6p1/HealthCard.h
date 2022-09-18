/* Workshop 6 Part 1
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 08/03/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

#include <iostream>

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
      void setEmpty();
      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
      void allocateAndCopy(const char* name);
      void extractChar(std::istream& istr, char ch) const;
      std::ostream& printIDInfo(std::ostream& ostr)const;
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);
   public:
       HealthCard();
       HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});    //constructor
       HealthCard(const HealthCard& hc);  //copy constructor
       HealthCard& operator=(const HealthCard& hc);    //copy assignment op.
       ~HealthCard();   //deconstructor
       operator bool() const;   //returns whether the health card is valid or not
       std::ostream& print(std::ostream& ostr, bool toFile = true) const;
       std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
   std::istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H



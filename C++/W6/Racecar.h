/*Workshop 6
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Autoshop.h"

namespace sdds
{
	class Racecar : public Car {
		double m_booster{};
		void cleanString(std::string& str);	//removes any spaces from beginning and end of given string
	public:
		Racecar(std::istream& istr);
		void display(std::ostream& ostr) const;
		double topSpeed() const;
	};
}
#endif // !SDDS_RACECAR_H

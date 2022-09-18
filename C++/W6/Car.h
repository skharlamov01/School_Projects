/*Workshop 6
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle {
		std::string m_maker{};
		char m_condition{};	//symbol representing condition of car: u = 'used', n = 'new', b = 'broken
		double m_topSpeed{};
		void cleanString(std::string& str);	//removes any spaces from beginning and end of given string
	public:
		Car() = default;
		Car(std::istream& istr);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& ostr) const;
	};
}
#endif // !SDDS_CAR_H

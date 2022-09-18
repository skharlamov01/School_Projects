/*Workshop 6
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <string>
#include "Racecar.h"

namespace sdds
{
	void Racecar::cleanString(std::string& str)
	{
		if (isspace(str[0])) {	//check if any spaces in front
			//clean all front spaces
			int i = 0;
			while (isspace(str[i])) {
				str.erase(i, 1);
			}
		}
		if (isspace(str[str.length() - 1])) {	//check if any spaces in back
			//clean all back spaces
			int i = str.length() - 1;
			while (isspace(str[i])) {
				str.erase(i--, 1);
			}
		}
	}
	Racecar::Racecar(std::istream& istr) : Car(istr)
	{
		std::string temp;
		std::getline(istr, temp, '\n');
		cleanString(temp);
		m_booster = std::stod(temp);
	}
	void Racecar::display(std::ostream& ostr) const
	{
		Car::display(ostr);
		ostr << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}
}
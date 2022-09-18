/*Workshop 6
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <cctype>
#include <iomanip>
#include <exception>
#include "Car.h"

namespace sdds
{
	void Car::cleanString(std::string& str)
	{
		if (isspace(str[0]) || str[0] == ',') {	//check if any spaces in front
			//clean all front spaces
			int i = 0;
			while (str[i] == ',' || isspace(str[i])) {
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
	Car::Car(std::istream& istr)
	{
		std::string temp;
		while (std::isspace(istr.peek())) {
			istr.ignore();
		}
		char peek = istr.peek();
		istr.ignore(50, ',');
		std::getline(istr, temp, ',');
		cleanString(temp);
		m_maker = temp;	//reading maker in with a sanitized input
		if (istr.peek() == ',') {
			m_condition = 'n';
		}
		else {
			std::getline(istr, temp, ',');
			bool hasAlpha = false;
			for (size_t i = 0; i < temp.length(); i++) {
				if (std::isalpha(temp[i])) {
					hasAlpha = true;
					break;
				}
			}
			if (hasAlpha) {
				cleanString(temp);
				if (temp == "n" || temp == "u" || temp == "b") {
					m_condition = temp[0];	//reading the condition in w a sanitized input
				}
				else {
					istr.ignore(50, '\n');
					throw std::exception();
				}
			}
			else {
				m_condition = 'n';
			}
		}
		if (peek == 'c' || peek == 'C') {
			std::getline(istr, temp, '\n');
			cleanString(temp);
			try {
				m_topSpeed = std::stod(temp);
			}
			catch (...) {
				istr.ignore(50, '\n');
				throw std::exception();
			}
		}
		else if (peek == 'r' || peek == 'R') {
			std::getline(istr, temp, ',');
			cleanString(temp);
			try {
				m_topSpeed = std::stod(temp);
			}
			catch (...) {
				istr.ignore(50, '\n');
				throw std::exception();
			}
		}
		else {
			istr.ignore(250, '\n');
		}
	}
	std::string Car::condition() const
	{
		std::string ret;
		switch (m_condition) {
		case 'n':
			ret = "new";
			break;
		case 'u':
			ret = "used";
			break;
		case 'b':
			ret = "broken";
			break;
		}
		return ret;
	}
	double Car::topSpeed() const
	{
		return m_topSpeed;
	}
	void Car::display(std::ostream& ostr) const
	{
		ostr << "| " << std::setw(10) << std::right << m_maker;
		ostr << " | " << std::setw(6) << std::left << condition();
		ostr << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
}
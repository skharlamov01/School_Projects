/*Workshop 8 lab
Module : Rectangle
Filename : Rectangle.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <iomanip>
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds
{
	Rectangle::Rectangle() : LblShape()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* tlabel, const int width, const int height) : LblShape(tlabel)
	{
		if (height >= 3 && (unsigned)width >= strlen(label()) + 2) {
			m_height = height;
			m_width = width;
		}
		else {
			m_height = 0;
			m_width = 0;
		}
	}
	void Rectangle::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		istr.ignore(1000, '\n');
	}
	void Rectangle::draw(ostream& ostr) const
	{
		if (m_height > 0 && m_width > 0 && label() != nullptr) {
			ostr << '+' << setw(m_width - 2) << setfill('-') << '-' << '+' << endl;
			ostr << '|' << left << setw(m_width - 2) << setfill(' ') << label() << '|' << endl;
			ostr.unsetf(ios::left);
			for (int i = 0; i < m_height - 3; i++) {
				ostr << '|' << setw(m_width - 1) << '|' << endl;
			}
			ostr << '+' << setw(m_width - 2) << setfill('-') << '-' << '+';
		}
	}
}
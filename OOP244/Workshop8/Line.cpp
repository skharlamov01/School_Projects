/*Workshop 8 lab
Module : Line
Filename : Line.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include "Line.h"

namespace sdds
{
	Line::Line() : LblShape()
	{
		m_length = 0;
	}
	Line::Line(const char* label, const int length) : LblShape(label)
	{
		m_length = length;
	}
	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& ostr) const
	{
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << std::endl;
			ostr.fill('=');
			ostr.width(m_length);
			ostr << '=';
		}
	}
}
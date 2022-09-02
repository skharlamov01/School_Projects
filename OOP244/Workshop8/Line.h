/*Workshop 8 lab
Module : Line
Filename : Line.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* label, const int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr) const;
	};
}
#endif // !SDDS_LINE_H

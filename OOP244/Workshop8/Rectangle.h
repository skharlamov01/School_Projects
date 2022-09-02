/*Workshop 8 lab
Module : Rectangle
Filename : Rectangle.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds
{
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* tlabel, const int width, const int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr) const;
	};
}
#endif // !SDDS_RECTANGLE_H

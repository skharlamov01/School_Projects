/*Workshop 8 lab
Module : Shape
Filename : Shape.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds
{
	class Shape {
	public:
		virtual ~Shape();
		virtual void draw(std::ostream& ostr) const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
}
#endif // !SDDS_SHAPE_H

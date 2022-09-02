/*Workshop 8 lab
Module : Shape
Filename : Shape.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include "Shape.h"

namespace sdds
{
    std::ostream& operator<<(std::ostream& ostr, const Shape& shape)
    {
        shape.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& shape)
    {
        shape.getSpecs(istr);
        return istr;
    }
    Shape::~Shape()
    {
    }
}
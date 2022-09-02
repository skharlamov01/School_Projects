/*Final Project Milestone 56
Module : iProduct
Filename : iProduct.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include "iProduct.h"

namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const iProduct& prod)
	{
		return prod.display(ostr);
	}
	std::istream& operator>>(std::istream& istr, iProduct& prod)
	{
		return prod.read(istr);
	}
}
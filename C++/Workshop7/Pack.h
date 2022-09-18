/*Workshop 7 lab
Module : Pack
Filename : Pack.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/17
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include <iostream>
#include "Container.h"

namespace sdds
{
	class Pack : public Container {
		int m_unitSize;
	public:
		Pack(const char desc[], const int size, const int usize = 330, const int unum = 0);
		int operator+=(int add);
		int operator-=(int sub);
		int unit() const;
		int noOfUnits() const;
		int size() const;
		void clear(int packSize, int unitSize, const char desc[]);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack);
	std::istream& operator>>(std::istream& istr, Pack& pack);
}
#endif // !SDDS_PACK_H

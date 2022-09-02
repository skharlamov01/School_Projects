/*Workshop 7 lab
Module : Container
Filename : Container.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/17
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <iostream>

namespace sdds
{
	class Container {
		char m_description[51];
		int m_capacity;
		int m_volume;
	protected:
		void setEmpty();
		int capacity() const;
		int volume() const;
	public:
		Container(const char desc[], const int capacity);
		Container(const char desc[], const int capacity, const int volume);
		int operator+=(int volume);
		int operator-=(int volume);
		operator bool() const;
		void clear(const int capacity, const char desc[]);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Container& con);
	std::istream& operator>>(std::istream& istr, Container& con);
}
#endif // !SDDS_CONTAINER_H

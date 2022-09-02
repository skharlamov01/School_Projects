/*Workshop 7 lab
Module : Container
Filename : Container.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/17
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>	//for the strcpy
#include "Container.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	void Container::setEmpty()
	{
		strcpy(m_description, "");
		m_capacity = -1;
		m_volume = -1;
	}
	int Container::capacity() const
	{
		return m_capacity;
	}
	int Container::volume() const
	{
		return m_volume;
	}
	Container::Container(const char desc[], const int capacity)
	{
		if (desc != nullptr) {
			strcpy(m_description, desc);
			m_capacity = capacity;
			m_volume = 0;
		}
		else {
			setEmpty();
		}
	}
	Container::Container(const char desc[], const int capacity, const int volume)
	{
		if (desc != nullptr && capacity >= volume) {
			strcpy(m_description, desc);
			m_capacity = capacity;
			m_volume = volume;
		}
		else {
			setEmpty();
		}
	}
	int Container::operator+=(const int volume)
	{
		int diff = 0;
		if (m_volume + volume >= m_capacity) {
			diff = m_capacity - m_volume;
			m_volume = m_capacity;
		}
		else {
			m_volume += volume;
			diff = volume;
		}
		return diff;
	}
	int Container::operator-=(const int volume)
	{
		int diff = 0;
		if (m_volume - volume <= 0) {
			diff = m_volume;
			m_volume = 0;
		}
		else {
			m_volume -= volume;
			diff = volume;
		}
		return diff;
	}
	Container::operator bool() const
	{
		if (strcmp(m_description, "") == 0 || m_capacity <= 0 || m_volume < 0) {
			return false;
		}
		else
			return true;
	}
	void Container::clear(const int capacity, const char desc[])
	{
		if (capacity > 0 && strcmp("", desc) != 0) {
			strcpy(m_description, desc);
			m_capacity = capacity;
			m_volume = 0;
		}
	}
	ostream& Container::print(ostream& ostr) const
	{
		if (*this) {
			cout << m_description << ": (";
			cout << m_volume << "cc/" << m_capacity << ")";
		}
		else {
			cout << "****: (**cc/***)";
		}
		return ostr;
	}
	istream& Container::read(istream& istr)
	{
		if (*this) {
			cout << "Add to " << *this << endl;
			int add = ut.getint(1, 999, "> ");
			cout << "Added " << (*this += add) << " CCs" << endl;
		}
		else {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore();
			istr.ignore();
		}
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Container& con)
	{
		return con.print(ostr);
	}
	istream& operator>>(istream& istr, Container& con)
	{
		return con.read(istr);
	}
}
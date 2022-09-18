/*Workshop 7 lab
Module : Pack
Filename : Pack.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/17
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include "Pack.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	Pack::Pack(const char desc[], const int size, const int usize, const int unum) : Container(desc, (size * usize), (unum * usize))
	{
		if (usize > 0) {
			m_unitSize = usize;
		}
		else {
			setEmpty();
			m_unitSize = 0;
		}
	}
	int Pack::operator+=(int add)
	{
		int value = Container::operator+=(add * m_unitSize);
		return value / m_unitSize;
	}
	int Pack::operator-=(int sub)
	{
		int value = Container::operator-=(sub * m_unitSize);
		return value / m_unitSize;
	}
	int Pack::unit() const
	{
		return m_unitSize;
	}
	int Pack::noOfUnits() const
	{
		return volume() / m_unitSize;
	}
	int Pack::size() const
	{
		return capacity() / m_unitSize;
	}
	void Pack::clear(int packSize, int unitSize, const char desc[])
	{
		if (unitSize > 0) {
			Container::clear(packSize * unitSize, desc);
			m_unitSize = unitSize;
		}
	}
	ostream& Pack::print(ostream& ostr) const
	{
		Container::print(ostr);
		if (m_unitSize > 0) {
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}
	istream& Pack::read(istream& istr)
	{
		if (*this) {
			if (noOfUnits() < size()) {
				cout << "Add to " << *this << endl;
				int diff = size() - noOfUnits();
				int add = ut.getint(1, diff, "> ");
				cout << "Added " << (*this += add) << endl;
			}
			else {
				cout << "Pack is full!, press <ENTER> to continue...";
				istr.ignore();
				istr.ignore();
			}
		}
		else {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore();
		}
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Pack& pack)
	{
		return pack.print(ostr);
	}
	istream& operator>>(istream& istr, Pack& pack)
	{
		return pack.read(istr);
	}
}
/*Workshop 3
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/05
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <iomanip>
#include "Pair.h"
using namespace std;
namespace sdds
{
	bool Pair::operator==(const Pair& item) const
	{
		if (m_key.compare(item.m_key) == 0) {
			return true;
		}
		return false;
	}
	ostream& Pair::display(ostream& ostr) const
	{
		ostr << right << setw(20) << m_key << ": " << left << m_value;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Pair& item)
	{
		return item.display(ostr);
	}
}
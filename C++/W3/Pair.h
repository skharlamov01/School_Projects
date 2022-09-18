/*Workshop 3
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/05
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <string>
#include <iostream>

namespace sdds
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() {
			return m_key;
		}
		const std::string& getValue() {
			return m_value;
		}
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		Pair() {}
		bool operator==(const Pair& item)const;
		std::ostream& display(std::ostream& ostr)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Pair& item);
}
#endif // !SDDS_PAIR_H

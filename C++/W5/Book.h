/*Workshop 5
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/17
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>

namespace sdds
{
	class Book {
		size_t m_pubYear;
		double m_price;
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		std::string m_desc{};
		void cleanString(std::string& str);	//removes any spaces from beginning and end of given string
	public:
		Book() : m_pubYear{ 0u }, m_price{ 0.00f } {};
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book& operator=(const Book& bk2);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);	//its gotta be either this
			//spellChecker::operator()(m_desc);	//or this
		}
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
	};
}
#endif // !SDDS_BOOK_H

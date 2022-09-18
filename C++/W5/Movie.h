/*Workshop 5
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/19
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <string>

namespace sdds
{
	class Movie {
		size_t m_year;
		std::string m_title{};
		std::string m_desc{};
		void cleanString(std::string& str);	//removes any spaces from beginning and end of given string
	public:
		Movie() : m_year{ 0 } {};
		Movie(const std::string& strMovie);
		const std::string& title() const;
		Movie& operator=(const Movie& m2);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
			spellChecker(m_title);
			//spellChecker::operator()(m_desc);	//or this option for the two
		}
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);
	};
}
#endif // !SDDS_MOVIE_H

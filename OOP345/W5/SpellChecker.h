/*Workshop 5
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/19
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_SPELLCHECK_H
#define SDDS_SPELLCHECK_H

#include <iostream>
#include <string>

namespace sdds
{
	class SpellChecker {
		size_t m_replaceNum[6]{};
		std::string m_badWords[6];
		std::string m_goodWords[6];
		std::string cleanString(std::string str);	//removes any spaces from beginning and end of given string
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECK_H

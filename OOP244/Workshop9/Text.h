/*Workshop 9 lab
Module : Text
Filename : Text.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/31
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <iostream>

namespace sdds
{
	class Text {
		char* m_content{};
	protected:
		const char& operator[](int index) const;
	public:
		Text() = default;
		Text(const Text& txt2);
		Text& operator=(const Text& txt2);
		virtual ~Text();
		int getFileLength(std::istream& is);
		std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Text& txt);
	std::istream& operator>>(std::istream& istr, Text& txt);
}
#endif // !SDDS_TEXT_H

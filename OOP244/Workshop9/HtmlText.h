/*Workshop 9 lab
Module : HTML Text
Filename : HtmlText.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/31
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include "Text.h"	//includes <iostream>

namespace sdds
{
	class HtmlText : public Text {
		char* m_title{};
	public:
		HtmlText() = default;
		HtmlText(const char* title);
		HtmlText(const HtmlText& txt2);
		HtmlText& operator=(const HtmlText& txt2);
		~HtmlText();
		std::ostream& write(std::ostream& ostr) const;
	};
}
#endif // !SDDS_HTMLTEXT_H

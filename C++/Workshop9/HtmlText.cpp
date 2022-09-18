/*Workshop 9 lab
Module : HTML Text
Filename : HtmlText.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/31
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "HtmlText.h"	//includes <iostream> thru Text.h
#include "Utils.h"	//includes <cstring> and <fstream>, <iostream> via "Utils.h"
using namespace std;
namespace sdds
{
	HtmlText::HtmlText(const char* title) : Text()
	{
		//ut.alocpy(m_title, title);
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
	}
	HtmlText::HtmlText(const HtmlText& txt2) : Text(txt2)
	{
		//ut.alocpy(m_title, txt2.m_title);
		delete[]m_title;
		m_title = new char[strlen(txt2.m_title) + 1];
		strcpy(m_title, txt2.m_title);
	}
	HtmlText& HtmlText::operator=(const HtmlText& txt2)
	{
		if (this != &txt2) {
			//ut.alocpy(m_title, txt2.m_title);
			delete[]m_title;
			m_title = new char[strlen(txt2.m_title) + 1];
			strcpy(m_title, txt2.m_title);
			Text::operator=(txt2);
		}
		return *this;
	}
	HtmlText::~HtmlText()
	{
		delete[]m_title;
		m_title = nullptr;
	}
	ostream& HtmlText::write(ostream& ostr) const
	{
		bool ms = false;
		ostr << "<html><head><title>";
		if (m_title != nullptr) {
			ostr << m_title;
		}
		else {
			ostr << "No Title";
		}
		ostr << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			ostr << "<h1>" << m_title << "</h1>\n";
		}
		for (int i = 0; Text::operator[](i); i++) {
			char ch = Text::operator[](i);
			if (ch == ' ') {
				if (ms == true) {
					ostr << "&nbsp;";
				}
				else {
					ms = true;
					ostr << ' ';
				}
			}
			else if (ch == '<') {
				ostr << "&lt;";
				ms = false;
			}
			else if (ch == '>') {
				ostr << "&gt;";
				ms = false;
			}
			else if (ch == '\n') {
				ostr << "<br />\n";
				ms = false;
			}
			else {
				ms = false;
				ostr << ch;
			}
		}
		ostr << "</body>\n</html>";
		return ostr;
	}
}
/*Workshop 9 lab
Module : Text
Filename : Text.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/31
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Text.h"	//includes <iostream>
#include "Utils.h"	//includes <cstring> and <fstream>, <iostream> via "Utils.h"
using namespace std;
namespace sdds
{
	const char& Text::operator[](int index) const
	{
		return m_content[index];
	}
	Text::Text(const Text& txt2)
	{
		//ut.alocpy(m_content, txt2.m_content);
		delete[]m_content;
		m_content = new char[strlen(txt2.m_content) + 1];
		strcpy(m_content, txt2.m_content);
	}
	Text& Text::operator=(const Text& txt2)
	{
		if (this != &txt2) {
			//ut.alocpy(m_content, txt2.m_content);
			delete[]m_content;
			m_content = new char[strlen(txt2.m_content) + 1];
			strcpy(m_content, txt2.m_content);
		}
		return *this;
	}
	Text::~Text()
	{
		delete[]m_content;
		m_content = nullptr;
	}
	int Text::getFileLength(std::istream& is) {
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}
	istream& Text::read(istream& istr)
	{
		delete[]m_content;
		int fsize = getFileLength(istr);
		m_content = new char[fsize + 1];
		for (int i = 0; i < fsize; i++) {
			m_content[i] = istr.get();
		}
		if (m_content != nullptr) {
			m_content[fsize] = '\0';
			istr.clear();
		}
		return istr;
	}
	ostream& Text::write(ostream& ostr) const
	{
		if (m_content != nullptr) {
			ostr << m_content;
		}
		return ostr;
	}
	ostream& operator<<(ostream& ostr, const Text& txt)
	{
		return txt.write(ostr);
	}
	istream& operator>>(istream& istr, Text& txt)
	{
		return txt.read(istr);
	}
}
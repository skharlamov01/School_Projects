/*Workshop 8 lab
Module : LabelShape
Filename : LblShape.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "LblShape.h"
using namespace std;

namespace sdds
{
	const char* LblShape::label() const
	{
		return (const char*)m_label;
	}
	LblShape::LblShape()
	{
		m_label = nullptr;
	}
	LblShape::LblShape(const char* str)
	{
		m_label = new char[strlen(str) + 1];
		strcpy(m_label, str);
	}
	LblShape::~LblShape()
	{
		delete[]m_label;
		m_label = nullptr;
	}
	void LblShape::getSpecs(std::istream& istr)
	{
		char tmpstr[1000];
		istr.get(tmpstr, 1000, ',');
		if (tmpstr != nullptr) {
			delete[] m_label;
			m_label = new char[strlen(tmpstr) + 1];
			strcpy(m_label, tmpstr);
		}
		istr.ignore();
	}
}
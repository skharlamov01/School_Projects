/*Final Project Milestone 3
Module : Status
Filename : Status.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/02/29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>	//using strlen and strcpy
#include "Utils.h"
#include "Status.h"
using namespace std;

namespace sdds
{
	Status& Status::clear()
	{
		delete[] m_desc;
		m_desc = nullptr;
		m_stat_code = 0;
		return *this;
	}
	Status::Status()
	{
		m_desc = nullptr;
		m_stat_code = 0;
	}
	Status::Status(const char* t_desc)
	{
		m_desc = new char[strlen(t_desc) + 1];
		strcpy(m_desc, t_desc);
		m_stat_code = 0;
	}
	Status::Status(const Status& stat2)
	{
		if (!stat2) {
			m_stat_code = stat2.m_stat_code;
			m_desc = new char[strlen(stat2.m_desc) + 1];
			strcpy(m_desc, stat2.m_desc);
		}
	}
	Status::~Status()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}
	Status& Status::operator=(const Status& stat2)
	{
		if (this != &stat2) {
			m_stat_code = stat2.m_stat_code;
			ut.alocpy(m_desc, stat2.m_desc);
		}
		return *this;
	}
	Status& Status::operator=(const int t_code)
	{
		m_stat_code = t_code;
		return *this;
	}
	Status& Status::operator=(const char* t_desc)
	{
		ut.alocpy(m_desc, t_desc);
		return *this;
	}
	Status::operator bool() const
	{
		return m_desc == nullptr ? true : false;
	}
	Status::operator int() const
	{
		return m_stat_code;
	}
	Status::operator const char* () const
	{
		return m_desc;
	}
	ostream& operator<<(ostream& ostr, const Status& status)
	{
		if (!status) {
			if ((int)status) {
				ostr << "ERR#" << (int)status << ": ";
			}
			ostr << (const char*)status;
		}
		return ostr;
	}
}
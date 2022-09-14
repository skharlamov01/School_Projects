/*Final Project Milestone 56
Module : Status
Filename : Status.h
Version 1.0
Author : Sasha Kharlamov
Date : 2022/04/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <iostream>

namespace sdds
{
	class Status {
		char* m_desc{};
		int m_stat_code;
	public:
		Status();
		Status(const char* t_desc);
		Status(const Status& stat2);
		~Status();
		Status& operator=(const Status& stat2);
		Status& operator=(const int t_code);	//sets the stat_code
		Status& operator=(const char* t_desc);	//deallocates and reallocates+assigns new string
		operator bool() const;	//returns true if desc is empty/null, false if not
		operator int() const;	//returns stat_code
		operator const char* () const;	//returns desc
		Status& clear();	//deallocates desc and sets stat_code to 0
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& status);
}
#endif // !SDDS_STATUS_H

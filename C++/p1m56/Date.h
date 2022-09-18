/*Final Project Milestone 56
Module : Date
Filename : Date.h
Version 1.0
Author : Sasha Kharlamov
Date : 2022/04/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include <iostream>
#include "Status.h"

namespace sdds
{
	const int max_year = 2030;
	class Date {
		int m_year;
		int m_month;
		int m_day;
		Status m_state;
		bool m_formatted;
		bool validate();	//returns true if date is valid, false otherwise
		int uniqDateValue(const int year, const int month, const int day);
	public:
		Date();
		Date(const int year, const int month, const int day);
		Date(const Date& date2);
		Date& operator=(const Date& date2);
		bool operator==(const Date& date2);
		bool operator!=(const Date& date2);
		bool operator<(const Date& date2);
		bool operator>(const Date& date2);
		bool operator<=(const Date& date2);
		bool operator>=(const Date& date2);
		Date& formatted(bool set);
		const Status& state() const;	//returns status of Date
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Date& date);
	std::istream& operator>>(std::istream& istr, Date& date);
}
#endif // !SDDS_DATE_H

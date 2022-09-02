/*Final Project Milestone 54
Module : Date
Filename : Date.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/08
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include "Date.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	bool Date::validate()
	{
		bool valid = true;
		int year = 0, month = 0, day = 0;
		ut.getSystemDate(&year, &month, &day);
		if (m_year < year || m_year > max_year) {
			m_state = "Invalid year in date";
			m_state = 1;
			valid = false;
		}
		else if (m_month < 1 || m_month > 12) {
			m_state = "Invalid month in date";
			m_state = 2;
			valid = false;
		}
		else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
			m_state = "Invalid day in date";
			m_state = 3;
			valid = false;
		}
		else {
			m_state.clear();
		}
		return valid;
	}
	int Date::uniqDateValue(const int year, const int month, const int day)
	{
		return year * 372 + month * 31 + day;
	}
	Date::Date()
	{
		ut.getSystemDate(&m_year, &m_month, &m_day);
		m_formatted = true;
	}
	Date::Date(const int year, const int month, const int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
		validate();
		m_formatted = true;
	}
	Date::Date(const Date& date2)
	{
		m_year = date2.m_year;
		m_month = date2.m_month;
		m_day = date2.m_day;
		m_state = date2.m_state;
		m_formatted = date2.m_formatted;
	}
	Date& Date::operator=(const Date& date2)
	{
		if (this != &date2) {
			m_year = date2.m_year;
			m_month = date2.m_month;
			m_day = date2.m_day;
			m_state = date2.m_state;
			m_formatted = date2.m_formatted;
		}
		return *this;
	}
	bool Date::operator==(const Date& date2)
	{
		return uniqDateValue(m_year, m_month, m_day) == uniqDateValue(date2.m_year, date2.m_month, date2.m_day) ? true : false;
	}
	bool Date::operator!=(const Date& date2)
	{
		return uniqDateValue(m_year, m_month, m_day) != uniqDateValue(date2.m_year, date2.m_month, date2.m_day) ? true : false;
	}
	bool Date::operator<(const Date& date2)
	{
		return uniqDateValue(m_year, m_month, m_day) < uniqDateValue(date2.m_year, date2.m_month, date2.m_day) ? true : false;
	}
	bool Date::operator>(const Date& date2)
	{
		return uniqDateValue(m_year, m_month, m_day) > uniqDateValue(date2.m_year, date2.m_month, date2.m_day) ? true : false;
	}
	bool Date::operator<=(const Date& date2)
	{
		return uniqDateValue(m_year, m_month, m_day) <= uniqDateValue(date2.m_year, date2.m_month, date2.m_day) ? true : false;
	}
	bool Date::operator>=(const Date& date2)
	{
		return uniqDateValue(m_year, m_month, m_day) >= uniqDateValue(date2.m_year, date2.m_month, date2.m_day) ? true : false;
	}
	Date& Date::formatted(bool set)
	{
		m_formatted = set;
		return *this;
	}
	const Status& Date::state() const
	{
		return m_state;
	}
	ostream& Date::write(ostream& ostr) const
	{
		if (m_formatted) {
			ostr << m_year << "/";
			ostr.width(2);
			ostr.fill('0');
			ostr << m_month << "/" << m_day;
		}
		else {
			ostr << m_year % 100;
			ostr.width(2);
			ostr.fill('0');
			ostr << m_month << m_day;
		}
		return ostr;
	}
	istream& Date::read(istream& istr)
	{
		int date;
		istr >> date;
			if (istr.fail()) {
				m_state = "Invalid date value";
			}
			else {
				if (date <= 1231) {
					ut.getSystemDate(&m_year);
					m_month = date / 100;
					m_day = date % 100;
				}
				else if (date > 99999 && date <= 999999) {
					m_year = date / 10000;
					date -= m_year * 10000;
					m_year += 2000;
					m_month = date / 100;
					m_day = date - m_month * 100;
				}
				if (!validate()) {
					istr.setstate(ios::badbit);
				}
			}
		return istr;
	}
	Date::operator bool() const
	{
		return state();
	}
	ostream& operator<<(ostream& ostr, const Date& date)
	{
		return date.write(ostr);
	}
	istream& operator>>(istream& istr, Date& date)
	{
		return date.read(istr);
	}
}
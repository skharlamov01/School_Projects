/*Workshop 1
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/05/22
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>	//used for working with c-style strings in constructor and read()
#include <string>	//used for the string class utility in read()
#include <iomanip>	//used for formatting in display()
#include "foodorder.h"	//includes <iostream>

using namespace std;

double g_taxrate = 0.00;
double g_dailydiscount = 0.00;

namespace sdds
{
	FoodOrder::FoodOrder()
	{
		strcpy(m_custname, "");
		m_price = 0.00;
		m_isDaily = false;
	}
	FoodOrder::FoodOrder(const FoodOrder& order2)
	{
		delete[]m_fooddesc;
		m_fooddesc = nullptr;
		strcpy(m_custname, order2.m_custname);
		m_fooddesc = new char[strlen(order2.m_fooddesc) + 1];
		strcpy(m_fooddesc, order2.m_fooddesc);
		m_price = order2.m_price;
		m_isDaily = order2.m_isDaily;
	}
	FoodOrder& FoodOrder::operator=(const FoodOrder& order2)
	{
		if (this != &order2) {
			delete[]m_fooddesc;
			m_fooddesc = nullptr;
			strcpy(m_custname, order2.m_custname);
			m_fooddesc = new char[strlen(order2.m_fooddesc) + 1];
			strcpy(m_fooddesc, order2.m_fooddesc);
			m_price = order2.m_price;
			m_isDaily = order2.m_isDaily;
		}
		return *this;
	}
	istream& FoodOrder::read(istream& istr)
	{
		string desc;
		char isDaily;
		if (istr.good()) {
			delete[]m_fooddesc;
			m_fooddesc = nullptr;
			istr.getline(m_custname, 10, ',');
			getline(istr, desc, ',');
			m_fooddesc = new char[desc.length() + 1];
			strcpy(m_fooddesc, desc.c_str());
			istr >> m_price;
			istr.ignore();
			istr >> isDaily;
			m_isDaily = isDaily == 'Y' ? true : false;
			istr.ignore();	//to skip new line after one record
		}
		return istr;
	}
	void FoodOrder::display() const
	{
		static int counter = 1;
		cout.setf(ios::left);
		cout.fill(' ');
		cout << setw(2) << counter << ". ";
		if (strlen(m_custname) > 0) {
			cout << setw(10) << m_custname << '|';
			cout << setw(25) << m_fooddesc << '|';
			cout << setw(12) << fixed << setprecision(2) << m_price + (m_price * g_taxrate) << '|';
			if (m_isDaily) {
				cout << right << setw(13) << m_price + (m_price * g_taxrate) - g_dailydiscount;
				cout.unsetf(ios::right);
			}
			cout << endl;
		}
		else {
			cout << "No Order" << endl;
		}
		counter++;
	}
	FoodOrder::~FoodOrder()
	{
		delete[]m_fooddesc;
		m_fooddesc = nullptr;
	}
}
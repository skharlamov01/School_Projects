/*Final Project Milestone 53
Module : Item
Filename : Item.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/08
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <cstring>
#include <iomanip>
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	bool Item::linear() const
	{
		return m_isLinear;
	}
	Item::Item()
	{
		m_handQty = m_needQty = m_sku = 0;
		m_price = 0.00f;
		m_isLinear = false;
		m_desc = nullptr;
	}
	Item::Item(const Item& item2)
	{
		if (m_state) {
			m_price = item2.m_price;
			m_handQty = item2.m_handQty;
			m_needQty = item2.m_needQty;
			ut.alocpy(m_desc, item2.m_desc);
			m_isLinear = item2.m_isLinear;
			m_state = item2.m_state;
			m_sku = item2.m_sku;
		}
	}
	Item& Item::operator=(const Item& item2)
	{
		if (m_state) {
			m_price = item2.m_price;
			m_handQty = item2.m_handQty;
			m_needQty = item2.m_needQty;
			ut.alocpy(m_desc, item2.m_desc);
			m_isLinear = item2.m_isLinear;
			m_state = item2.m_state;
			m_sku = item2.m_sku;
		}
		return *this;
	}
	Item::~Item()
	{
		delete[]m_desc;
		m_desc = nullptr;
	}
	Item::operator double() const
	{
		return m_price;
	}
	Item::operator bool() const
	{
		return m_state;
	}
	int Item::qtyNeeded() const
	{
		return m_needQty;
	}
	int Item::qty() const
	{
		return m_handQty;
	}
	void Item::linear(bool isLinear)
	{
		m_isLinear = isLinear;
	}
	int Item::operator-=(int qty)
	{
		if (m_handQty - qty <= 0) {
			m_handQty = 0;
		}
		else {
			m_handQty -= qty;
		}
		return m_handQty;
	}
	int Item::operator+=(int qty)
	{
		return m_handQty+=qty;
	}
	void Item::clear()
	{
		m_state.clear();
	}
	bool Item::operator==(int sku) const
	{
		return m_sku == sku ? true : false;
	}
	bool Item::operator==(const char* description) const
	{
		return strstr(m_desc, description) != nullptr ? true : false;
	}
	int Item::readSku(istream& istr)
	{
		int sku = 0;
		sku = ut.getint(40000, 99999, "SKU: ");
		m_sku = sku;
		return sku;
	}
	ofstream& Item::save(ofstream& ofstr) const
	{
		if (m_state) {
			ofstr << m_sku << "\t" << m_desc << "\t" << m_handQty << "\t" << m_needQty << "\t" << fixed << setprecision(2) << m_price;
		}
		return ofstr;
	}
	ifstream& Item::load(ifstream& ifstr)
	{
		if (ifstr.bad()) {
			m_state = "Input file stream read failed!";
		}
		else {
			char tstr[1000];
			ifstr >> m_sku;
			ifstr.ignore();
			ifstr.get(tstr, 1000, '\t');
			ifstr.ignore();
			ut.alocpy(m_desc, tstr);
			ifstr >> m_handQty;
			ifstr.ignore();
			ifstr >> m_needQty;
			ifstr.ignore();
			ifstr >> m_price;
			ifstr.ignore();
		}
		return ifstr;
	}
	ostream& Item::display(ostream& ostr) const
	{
		if (!m_state) {
			ostr << m_state;
		}
		else if (linear()) {
			ostr << m_sku << " | ";
			ostr.setf(ios::left);
			ostr.fill(' ');
			if (strlen(m_desc) > 35) {
				ostr.write(m_desc, 35);
			}
			else {
				ostr.width(35);
				cout << m_desc;
			}
			ostr << " | " << setw(4) << right << m_handQty;
			ostr << " | " << setw(4) << m_needQty;
			ostr << " | " << setw(7) << fixed << setprecision(2) << m_price << " |";
			cout.unsetf(ios::right);
		}
		else {
			ostr << "AMA Item:" << endl;
			ostr << m_sku << ": " << m_desc << endl;
			ostr << "Quantity Needed: " << m_needQty << endl;
			ostr << "Quantity Available: " << m_handQty << endl;
			ostr << "Unit Price: $" << fixed << setprecision(2) << m_price << endl;
			ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << m_price * (m_needQty - m_handQty) << endl;
		}
		return ostr;
	}
	istream& Item::read(istream& istr)
	{
		if (istr.bad()) {
			m_state = "Console entry failed!";
		}
		else {
			char tstr[1000];
			m_state.clear();
			cout << "AMA Item:" << endl;
			cout << "SKU: " << m_sku << endl;
			cout << "Description: ";
			if (istr.peek() == '\n') {
				istr.ignore();
			}
			istr.get(tstr, 1000, '\n');
			ut.alocpy(m_desc, tstr);
			m_needQty = ut.getint(1, 9999, "Quantity Needed: ");
			m_handQty = ut.getint(0, m_needQty, "Quantity On Hand: ");
			m_price = ut.getdouble(0.0, 9999.0, "Unit Price: $");
		}
		return istr;
	}
}
/* Workshop 6 Part 1
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 08/03/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>	//for the strlen and strcpy, used in constructors
#include <cctype>	//for isalpha and isalnum, used in validation
#include "HealthCard.h"
using namespace std;
namespace sdds {

	HealthCard::HealthCard() {
		m_name = nullptr;
		m_number = 0;
		m_vCode[3] = {};
		m_sNumber[10] = {};
	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc) {
		if (hc) {
			m_number = hc.m_number;
			strcpy(m_vCode, hc.m_vCode);
			strcpy(m_sNumber, hc.m_sNumber);
			m_name = new char[strlen(hc.m_name) + 1];
			strcpy(m_name, hc.m_name);
		}
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (this != &hc) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}

	HealthCard::~HealthCard() {
		delete[] m_name;
		m_name = nullptr;
	}

	void HealthCard::setEmpty(){
		m_name = nullptr;
	}

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		if (name == nullptr || strlen(name) == 0 || strlen(name) > 55) {
			return false;
		}
		if (number <= 999999999 || number > 9999999999) {
			return false;
		}
		if (!isalpha(vCode[0]) || !isalpha(vCode[1])) {
			return false;
		}
		if (strlen(sNumber) != 9) {
			return false;
		}
		for (int i = 0; i < strlen(sNumber) - 1; i++) {
			if (!isalnum(sNumber[i]))
				return false;
		}
		return true;
	}

	void HealthCard::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const {
		char next = istr.peek();
		if (next == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr)const {
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			delete[] m_name;
			setEmpty();
		}
	}

	HealthCard::operator bool() const {
		return m_name != nullptr ? true : false;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const {
		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile) {
				ostr << m_name << ",";
				printIDInfo(ostr);
				ostr << endl;
			}
			else {
				ostr.width(50);
				ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_name;
				printIDInfo(ostr);
			}
		}
		return ostr;
	}

	istream& HealthCard::read(istream& istr) {
		char tmp_name[MaxNameLength+1];
		long long tmp_number = 0;
		char tmp_vCode[3];
		char tmp_sNumber[10];

		istr.get(tmp_name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> tmp_number;
		extractChar(istr, '-');
		istr.get(tmp_vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(tmp_sNumber, 10, '\n');
		extractChar(istr, '\n');

		if (istr.fail()) {
			istr.clear();
			istr.ignore(1000, '\n');
		}
		else {
			set(tmp_name, tmp_number, tmp_vCode, tmp_sNumber);
		}
		return istr;
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc) {
		if (hc) {
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}

	istream& operator>>(istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}
}

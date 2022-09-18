/* Workshop 4 Part 1
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 09/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>	//for the printInfo formatting (setw, setprecision, etc.)
#include <cstring>	//for the strlen and strcmp
#include "CarInventory.h"
using namespace std;

namespace sdds
{
	void CarInventory::resetInfo()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = m_code = 0;
		m_price = 0.00f;
	}
	CarInventory::CarInventory()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = m_code = 0;
		m_price = 0.00f;
	}
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && (code > 99 && code < 1000) && price > 0) {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			resetInfo();
		}
	}
	CarInventory::~CarInventory()
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		resetInfo();	//resetting strings back to nullptrs and values back to 0
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		return *this;
	}
	void CarInventory::printInfo() const
	{
		cout.setf(ios::left);
		cout << "| " << setw(10) << m_type;
		cout << " | " << setw(16) << m_brand;
		cout << " | " << setw(16) << m_model;
		cout << " | " << m_year;
		cout.setf(ios::right);
		cout << " | " << setw(4) << m_code;
		cout << " | " << setw(9) << fixed << setprecision(2) << m_price << " |" << endl;
		cout.unsetf(ios::right);

	}
	bool CarInventory::isValid() const
	{
		bool tmp = false;
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && (m_code > 99 && m_code < 1000) && m_price > 0) {
			tmp = true;
		}
		return tmp;
	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool tmp = false;
		if (isValid() == true) {
			if (strcmp(m_type, car.m_type) == 0 && strcmp(m_model, car.m_model) == 0 && strcmp(m_brand, car.m_brand) == 0 && m_year == car.m_year) {
				tmp = true;
			}
		}
		return tmp;
	}
	bool find_similar(CarInventory car[], const int num_cars)
	{
		bool tmp = false;
		for (int i = 0; i < num_cars && tmp == false; i++) {
			for (int j = i + 1; j < num_cars && tmp == false; j++) {
				if (car[i].isSimilarTo(car[j])) {
					tmp = true;
				}
			}
		}
		return tmp;
	}
}
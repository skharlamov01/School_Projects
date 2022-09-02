/*Workshop 7
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/20
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cctype>
#include "CovidCollection.h"

namespace sdds
{
	void CovidCollection::cleanString(std::string& str)
	{
		if (isspace(str[0])) {	//check if any spaces in front
			//clean all front spaces
			int i = 0;
			while (isspace(str[i])) {
				str.erase(i, 1);
			}
		}
		if (isspace(str[str.length() - 1])) {	//check if any spaces in back
			//clean all back spaces
			int i = str.length() - 1;
			while (isspace(str[i])) {
				str.erase(i--, 1);
			}
		}
	}
	CovidCollection::CovidCollection(const char* filename)
	{
		Covid tempObj;	//for storing one line to be transferred into vector
		std::ifstream file(filename);
		if (!file) {
			throw std::exception();
			return;
		}
		do {
			std::string tempStr;
			std::getline(file, tempStr);
			if (tempStr.length() > 0) {
				std::string read = tempStr.substr(0, 25);
				cleanString(read);
				tempObj.m_country = read;
				read = tempStr.substr(25, 25);
				cleanString(read);
				tempObj.m_city = read;
				read = tempStr.substr(50, 25);
				cleanString(read);
				tempObj.m_variant = read;
				read = tempStr.substr(75, 5);
				cleanString(read);
				tempObj.m_year = stoi(read);
				read = tempStr.substr(80, 5);
				cleanString(read);
				tempObj.m_cases = stoi(read);
				m_totalCases += stoi(read);
				read = tempStr.substr(85, 5);
				cleanString(read);
				tempObj.m_deaths = stoi(read);
				m_totalDeaths += stoi(read);
				m_collection.push_back(tempObj);	//create a new index with temp object before reading from file again
			}
		} while (file);
			
	}
	void CovidCollection::sort(std::string field)
	{
		if (field == "country") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_country < b.m_country; });
		}
		else if (field == "variant") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_variant < b.m_variant; });
		}
		else if (field == "cases") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_cases < b.m_cases; });
		}
		else if (field == "deaths") {
			std::sort(m_collection.begin(), m_collection.end(), [](const Covid& a, const Covid& b) {return a.m_deaths < b.m_deaths; });
		}
		else {
			std::cerr << "Invalid sorting field!" << std::endl;
		}
	}
	void CovidCollection::cleanList()
	{
		std::transform(m_collection.begin(), m_collection.end(), m_collection.begin(),
			[=](Covid& cov) {
			if (cov.m_variant == "[None]")
				cov.m_variant.clear(); 
			return cov;
			});
	}
	bool CovidCollection::inCollection(const char* variant) const
	{
		return any_of(m_collection.begin(), m_collection.end(), [=](const Covid& cov) {return cov.m_variant == variant; });
	}
	std::list<Covid> CovidCollection::getListForCountry(const char* country) const
	{
		std::list<Covid> retList;
		copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(retList), [=](const Covid& cov) {return cov.m_country == country; });
		return retList;
	}
	std::list<Covid> CovidCollection::getListForVariant(const char* variant) const
	{
		std::list<Covid> retList;
		copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(retList) , [=](const Covid& cov) {return cov.m_variant == variant; });
		return retList;
	}
	void CovidCollection::display(std::ostream& out) const
	{
		for_each(m_collection.begin(), m_collection.end(), [=, &out](const Covid& cov) -> std::ostream& { return out << cov << std::endl; });
		out << std::setw(91) << std::setfill('-');
		out << "\n| " << std::setfill(' ') << std::setw(79) << std::right << "Total Cases Around the World:  " << m_totalCases << " |" << std::endl;
		out << "| " << std::setw(79) << std::right << "Total Deaths Around the World:  " << m_totalDeaths << " |" << std::endl;
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		std::cout << "| " << std::setw(21) << std::left << theCovid.m_country;
		std::cout << " | " << std::setw(15) << theCovid.m_city;
		std::cout << " | " << std::setw(20) << theCovid.m_variant;
		if (theCovid.m_year > 0) {
			std::cout << " | " << std::setw(6) << std::right << theCovid.m_year;
		}
		else {
			std::cout << std::right << " |       ";
		}
		std::cout << " | " << std::setw(4) << theCovid.m_cases << " | ";
		std::cout << std::setw(3) << theCovid.m_deaths << " |";
		return out;
	}
}
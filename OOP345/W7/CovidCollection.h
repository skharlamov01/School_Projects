/*Workshop 7
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/19
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_COVID_H
#define SDDS_COVID_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds
{
	struct Covid {
		std::string m_country{};
		std::string m_city{};
		std::string m_variant{};
		int m_year{};
		int m_cases{};
		int m_deaths{};
	};

	class CovidCollection {
		std::vector<Covid> m_collection{};
		int m_totalCases{};
		int m_totalDeaths{};
		void cleanString(std::string& str);	//removes any spaces from beginning and end of given string
	public:
		CovidCollection(const char* filename);
		void sort(std::string field);
		void cleanList();
		bool inCollection(const char* variant) const;
		std::list<Covid> getListForCountry(const char* country) const;
		std::list<Covid> getListForVariant(const char* variant) const;
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}

#endif // !SDDS_COVID_H

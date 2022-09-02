/*Final Project Milestone 56
Module : Perishable
Filename : Perishable.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_PERISH_H
#define SDDS_PERISH_H

#include "Item.h"
#include "Date.h"

namespace sdds
{
	class Perishable : public Item {
		Date m_expiry;
		char* m_handling = nullptr;
	public:
		Perishable();
		Perishable(const Perishable& item);
		Perishable& operator=(const Perishable& item);
		~Perishable();
		operator bool() const;
		const Date& expiry() const;
		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_PERISH_H
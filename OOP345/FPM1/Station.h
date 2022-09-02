// Name: Sasha Kharlamov
// Seneca Student ID: 150707214
// Seneca email: skharlamov@myseneca.ca
// Date of completion: 2022/07/29
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include <string>
#include "Utilities.h"

namespace sdds
{
	class Station {
		int m_id{};
		std::string m_item{};
		std::string m_desc{};
		unsigned int m_serialNum{};
		unsigned int m_numItems{};
		static unsigned int m_widthField;
		static int id_generator;
	public:
		Station(const std::string str);
		const std::string& getItemName() const;
		std::size_t getNextSerialNumber();
		std::size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SDDS_STATION_H

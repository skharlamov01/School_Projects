// Name: Sasha Kharlamov
// Seneca Student ID: 150707214
// Seneca email: skharlamov@myseneca.ca
// Date of completion: 2022/08/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"

namespace sdds
{
	unsigned int Station::m_widthField = 0;
	int Station::id_generator = 0;
	Station::Station(const std::string str)
	{
		std::size_t pos = 0;
		bool more = false;
		Utilities util;
		m_item = util.extractToken(str, pos, more);
		m_serialNum = std::stoi(util.extractToken(str, pos, more));
		m_numItems = std::stoi(util.extractToken(str, pos, more));
		if (util.getFieldWidth() > Station::m_widthField)
			Station::m_widthField = util.getFieldWidth();
		m_desc = util.extractToken(str, pos, more);
		m_id = ++Station::id_generator;
	}
	const std::string& Station::getItemName() const
	{
		return m_item;
	}
	std::size_t Station::getNextSerialNumber()
	{
		return m_serialNum++;
	}
	std::size_t Station::getQuantity() const
	{
		return m_numItems;
	}
	void Station::updateQuantity()
	{
		if (m_numItems > 0) {
			m_numItems--;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		os << std::setw(3) << std::setfill('0') << std::right << m_id << " | ";
		os << std::setw(Station::m_widthField + 1) << std::setfill(' ') << std::left << m_item << " | ";
		os << std::setw(6) << std::setfill('0') << std::right << m_serialNum;
		if (full) {
			os << " | " << std::setw(4) << std::right << std::setfill(' ') << getQuantity() << " | ";
			os << std::left << m_desc << std::endl;
		}
		else {
			os << " | " << std::endl;
		}
	}
}
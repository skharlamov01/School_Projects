// Name: Sasha Kharlamov
// Seneca Student ID: 150707214
// Seneca email: skharlamov@myseneca.ca
// Date of completion: 2022/08/04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities util;
		size_t pos = 0;
		int numIndex = 1;
		bool more = true;
		m_name = util.extractToken(str, pos, more);
		m_product = util.extractToken(str, pos, more);
		size_t origPos = pos;	//to hold starting position of items in order to read again when recreating array
		while (more) {
			m_lstItem = new Item*[numIndex];
			for (int i = 0; i < numIndex; i++) {
				std::string temp = util.extractToken(str, pos, more);
				m_lstItem[i] = new Item(temp);
				m_cntItem++;
			}
			if (more) {
				for (int i = 0; i < numIndex; i++) {
					delete m_lstItem[i];
					m_lstItem[i] = nullptr;
				}
				delete[] m_lstItem;
				m_lstItem = nullptr;
				m_cntItem = 0;
				pos = origPos;
				numIndex++;
			}
		}
		if (util.getFieldWidth() > CustomerOrder::m_widthField)	CustomerOrder::m_widthField = util.getFieldWidth();
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& obj)
	{
		throw std::exception();
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept
	{
		operator=(std::move(obj));
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) noexcept
	{
		if (this != &obj) {
			if (m_lstItem != nullptr) {
				for (size_t i = 0; i < m_cntItem; i++) {
					delete m_lstItem[i];
					m_lstItem[i] = nullptr;
				}
				delete[] m_lstItem;
				m_lstItem = nullptr;
			}
			m_lstItem = obj.m_lstItem;
			/*for (size_t i = 0; i < obj.m_cntItem; i++) {
				delete obj.m_lstItem[i];
				obj.m_lstItem[i] = nullptr;
			}
			delete[] obj.m_lstItem;*/
			obj.m_lstItem = nullptr;
			m_name = obj.m_name;
			m_product = obj.m_product;
			m_cntItem = obj.m_cntItem;
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		if (m_lstItem != nullptr) {
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;
		}
	}
	bool CustomerOrder::isOrderFilled() const
	{
		bool retValue = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled)	retValue = false;
		}
		return retValue;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool isFilled = true;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				if (!m_lstItem[i]->m_isFilled)	isFilled = false;
			}
		}
		return isFilled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool containsItem = false;
		int savedIndex = 0;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				savedIndex = i;
				containsItem = true;
				break;
			}
		}
		if (containsItem) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[savedIndex]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[savedIndex]->m_isFilled = true;
				os << "\tFilled " << m_name << ", " << m_product << " [" << m_lstItem[savedIndex]->m_itemName << "]" << std::endl;
			}
			else {
				os << "\tUnable to fill " << m_name << ", " << m_product << " [" << m_lstItem[savedIndex]->m_itemName << "]" << std::endl;
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(m_widthField + 2) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled) {
				os << "FILLED" << std::endl;
			}
			else {
				os << "TO BE FILLED" << std::endl;
			}
		}
	}
}
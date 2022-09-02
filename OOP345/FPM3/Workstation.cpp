// Name: Sasha Kharlamov
// Seneca Student ID: 150707214
// Seneca email: skharlamov@myseneca.ca
// Date of completion: 2022/08/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

namespace sdds
{
	std::deque<CustomerOrder> g_pending{};
	std::deque<CustomerOrder> g_completed{};
	std::deque<CustomerOrder> g_incomplete{};
	void Workstation::fill(std::ostream& os)
	{
		if (m_orders.size() > 0) {
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool succeeded = false;
		if (m_pNextStation == nullptr) {
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0) {
				if (m_orders.front().isOrderFilled()) {
					g_completed.push_back(std::move(m_orders.front()));
				}
				else {
					g_incomplete.push_back(std::move(m_orders.front()));
				}
				m_orders.pop_front();
				succeeded = true;
			}
		}
		else {
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0) {
				*m_pNextStation += std::move(m_orders.front());
				m_orders.pop_front();
				succeeded = true;
			}
		}
		return succeeded;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	size_t Workstation::getOrderListSize() const
	{
		return m_orders.size();
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() << " --> ";
		if (m_pNextStation == nullptr) {
			os << "End of Line" << std::endl;
		}
		else {
			os << m_pNextStation->getItemName() << std::endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}
// Name: Sasha Kharlamov
// Seneca Student ID: 150707214
// Seneca email: skharlamov@myseneca.ca
// Date of completion: 2022/08/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

//#include <iostream>
#include <deque>
#include "CustomerOrder.h"

namespace sdds
{
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{ nullptr };
	public:
		Workstation(const std::string str) : Station(str) {};
		Workstation(const Workstation& obj) = delete;
		Workstation& operator=(const Workstation& obj) = delete;
		Workstation(Workstation&& obj) = delete;
		Workstation& operator=(Workstation&& obj) = delete;
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		size_t getOrderListSize() const;
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif // !SDDS_WORKSTATION_H

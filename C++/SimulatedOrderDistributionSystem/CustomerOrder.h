// Name: Sasha Kharlamov
// Date of completion: 2022/08/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTORDER_H
#define SDDS_CUSTORDER_H

#include <iostream>
#include <string>
#include "Station.h"

namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{0};
		Item** m_lstItem{nullptr};
		static size_t m_widthField;
	public:
		CustomerOrder() = default;
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& obj);	//throws exception if called
		CustomerOrder& operator=(const CustomerOrder& obj) = delete;
		CustomerOrder(CustomerOrder&& obj) noexcept;
		CustomerOrder& operator=(CustomerOrder&& obj) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		//std::string getItemName() const;
		//std::string getItemNameByIndex(const int index) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_CUSTORDER_H

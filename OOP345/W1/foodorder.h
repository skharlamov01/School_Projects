/*Workshop 1
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/05/22
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
	class FoodOrder {
		char m_custname[10];
		char* m_fooddesc{};
		double m_price;
		bool m_isDaily;
	public:
		FoodOrder();
		FoodOrder(const FoodOrder& order2);
		FoodOrder& operator=(const FoodOrder& order2);
		std::istream& read(std::istream& is);
		void display() const;
		~FoodOrder();
	};
}

#endif // !SDDS_FOODORDER_H

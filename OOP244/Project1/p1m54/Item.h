/*Final Project Milestone 54
Module : Item
Filename : Item.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/08
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "iProduct.h"
#include "Status.h"

namespace sdds
{
	class Item : public iProduct{
		double m_price;
		int m_handQty;
		int m_needQty;
		char* m_desc = nullptr;
		bool m_isLinear;
	protected:
		Status m_state;
		int m_sku;
		bool linear() const;
	public:
		Item();
		Item(const Item& item2);
		Item& operator=(const Item& item2);
		~Item();
		// returns the price of the produce
		operator double()const;
		// returns if the Item is in a good state
		operator bool()const;
		// returns the number of products needed
		int qtyNeeded()const;
		// retuns the quantity on hand
		int qty()const;
		// determines if the Item is displayed in a linear format or 
		// descriptive format
		void linear(bool isLinear);
		// to reduce the quantity on hand
		int operator-=(int qty);
		// to increase the quantity on hand
		int operator+=(int qty);
		void clear();
		// returns true if the sku is a match to the Item's sku
		bool operator==(int sku)const;
		// returns true if the description is found in the Item's description
		bool operator==(const char* description)const;
		// to read the Stock-Keeping Unit from console before
		// main data entry
		int readSku(std::istream& istr);
		// saves the Item into a file
		std::ofstream& save(std::ofstream& ofstr)const;
		// loads an Item from a file
		std::ifstream& load(std::ifstream& ifstr);
		// displays the Item on the screen
		std::ostream& display(std::ostream& ostr)const;
		// reads the Item from the console
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_ITEM_H

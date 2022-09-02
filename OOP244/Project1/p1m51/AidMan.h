/*Final Project Milestone 51
Module : Aid Management
Filename : AidMan.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/22
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include "Menu.h"
#include "iProduct.h"

namespace sdds
{
	const int sdds_max_num_items = 100;
	class AidMan {
		char* m_fname;
		Menu m_menu;
		iProduct* m_products[sdds_max_num_items];
		int m_numProducts;
		int menu();
		void save();
		void deallocate();
		bool load();
		int list(const char* sub_desc = nullptr);
	public:
		AidMan();
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan&) = delete;
		~AidMan();
		void run();
	};
}
#endif // !SDDS_AIDMAN_H

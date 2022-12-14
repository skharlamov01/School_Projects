/*Final Project Milestone 56
Module : Menu
Filename : Menu.h
Version 1.0
Author : Sasha Kharlamov
Date : 2022/04/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	class Menu {
		char* m_content;
		int m_num;	//holds the number of options
	public:
		Menu(const int num, const char* content);
		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;
		~Menu();
		int run();
	};
}
#endif // !SDDS_MENU_H

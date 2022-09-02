/*Final Project Milestone 51
Module : Menu
Filename : Menu.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/22
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

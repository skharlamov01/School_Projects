/*Final Project Milestone 53
Module : Menu
Filename : Menu.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/08
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	Menu::Menu(const int num, const char* content)
	{
		if (content != nullptr && num <= 15) {
			m_num = num;
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
		else {
			m_num = -1;
			m_content = nullptr;
		}
	}
	Menu::~Menu()
	{
		delete[] m_content;
		m_content = nullptr;
	}
	int Menu::run()
	{
		int select = 0;
		cout << m_content << "0- Exit" << endl;
		select = ut.getint(0, m_num, "> ");
		return select;
	}
}
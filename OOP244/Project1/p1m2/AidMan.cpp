/*Final Project Milestone 2
Module : Aid Management
Filename : AidMan.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/22
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <iostream>
#include "AidMan.h"
#include "Date.h"
using namespace std;
namespace sdds
{
    int AidMan::menu()
    {
        int select = 0;
        cout << "Aid Management System Version 0.1" << endl;
        cout << "Date: " << Date() << endl;
        if (m_fname != nullptr) {
            cout << "Data file: " << m_fname << endl;
        }
        else {
            cout << "Data file: No file" << endl;
        }
        cout << "---------------------------------" << endl;
        select = m_menu.run();
        return select;
    }
    AidMan::AidMan() : m_menu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n")
    {
        m_fname = nullptr;
    }
    AidMan::~AidMan()
    {
        delete[]m_fname;
        m_fname = nullptr;
    }
    void AidMan::run()
    {
        bool exit = false;
        do {
            int select = menu();
            if (select == 1) {
                cout << "\n****List Items****\n" << endl;
            }
            else if (select == 2) {
                cout << "\n****Add Item****\n" << endl;
            }
            else if (select == 3) {
                cout << "\n****Remove Item****\n" << endl;
            }
            else if (select == 4) {
                cout << "\n****Update Quantity****\n" << endl;
            }
            else if (select == 5) {
                cout << "\n****Sort****\n" << endl;
            }
            else if (select == 6) {
                cout << "\n****Ship Items****\n" << endl;
            }
            else if (select == 7) {
                cout << "\n****New/Open Aid Database****\n" << endl;
            }
            else {
                exit = true;
                cout << "Exiting Program!" << endl;
            }
        } while (!exit);
    }
}
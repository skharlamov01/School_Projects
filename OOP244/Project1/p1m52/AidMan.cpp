/*Final Project Milestone 52
Module : Aid Management
Filename : AidMan.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/07
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <iostream>
#include <fstream>
#include "AidMan.h"
#include "Perishable.h"
#include "Date.h"   //provides <iostream>
#include "Utils.h"
using namespace std;
namespace sdds
{
    AidMan::AidMan() : m_menu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n")
    {
        for (int i = 0; i < sdds_max_num_items; i++) {
            m_products[i] = nullptr;
        }
        m_fname = nullptr;
        m_numProducts = 0;
    }
    AidMan::~AidMan()
    {
        for (int i = 0; i < sdds_max_num_items; i++) {
            delete m_products[i];
        }
        delete[]m_fname;
        m_fname = nullptr;
    }
    int AidMan::menu()
    {
        int select = 0;
        cout << "Aid Management System" << endl;
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
    void AidMan::save()
    {
        if (m_fname != nullptr) {
            ofstream fout(m_fname);
            for (int i = 0; i < m_numProducts; i++) {
                m_products[i]->save(fout);
                fout << endl;
            }
        }
    }
    void AidMan::deallocate()
    {
        for (int i = 0; i < sdds_max_num_items; i++) {
            delete m_products[i];
        }
        delete[]m_fname;
        m_fname = nullptr;
        m_numProducts = 0;
    }
    bool AidMan::load()
    {
        bool recordLoaded = false;
        char temp_fname[1000];
        deallocate();
        cin >> temp_fname;
        ut.alocpy(m_fname, temp_fname);
        ifstream fin(m_fname);
        if (!fin) {
            cout << "Failed to open " << m_fname << " for reading!" << endl;
            cout << "Would you like to create a new data file?" << endl;
            cout << "1- Yes!\n0- Exit" << endl;
            int choice = ut.getint(0, 1, "> ");
            if (choice == 1) {
                ofstream fnew(m_fname);
            }
            fin.clear();
        }
        else {
            while (fin.good()) {
                //find next open index in products array
                int openIndex = findOpenIndex();
                char c = fin.peek();
                if (c == '1' || c == '2' || c == '3') { //SKUs starting from 1 - 3 are perishables
                    m_products[openIndex] = new Perishable();
                }
                else if (c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {    //SKUs starting from 4 - 9 are regular items
                    m_products[openIndex] = new Item();
                }
                else {
                    fin.setstate(ios::badbit);
                }
                //once space has been allocated, load data in from file
                if (fin.good()) {
                    m_products[openIndex]->load(fin);
                    if (m_products[openIndex]) {
                        m_numProducts++;
                    }
                    else {
                        delete m_products[openIndex];
                    }
                }
            }
        }
        return recordLoaded;
    }
    int AidMan::findOpenIndex() //returns -1 if no open spots in database
    {
        int openIndex = -1;
        for (int i = 0; i < sdds_max_num_items; i++) {
            if (m_products[i] == nullptr) {
                openIndex = i;
                break;
            }
        }
        return openIndex;
    }
    int AidMan::list(const char* sub_desc)
    {
        int numPrint = 0;
        cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
        cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
        if (sub_desc != nullptr) {
            for (int i = 0; i < m_numProducts; i++) {
                if (*m_products[i] == sub_desc) {
                    m_products[i]->linear(true);
                    cout.width(3);
                    cout.setf(ios::right);
                    cout.fill(' ');
                    cout << ' ' << i + 1 << " | ";
                    cout.unsetf(ios::right);
                    cout << *m_products[i] << endl;
                    numPrint++;
                }
            }
        }
        else { 
            for (int i = 0; i < m_numProducts; i++) {
                m_products[i]->linear(true);
                cout.width(3);
                cout.setf(ios::right);
                cout.fill(' ');
                cout << ' ' << i + 1 << " | ";
                cout.unsetf(ios::right);
                cout << *m_products[i] << endl;
                numPrint++;
            }
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
        }
        return numPrint;
    }
    int AidMan::search(int sku) const
    {
        int foundSKU = -1;
        for (int i = 0; i < m_numProducts && foundSKU == -1; i++) {
            if (*m_products[i] == sku) {
                foundSKU = i;
            }
        }
        return foundSKU;
    }
    void AidMan::run()
    {
        bool exit = false;
        do {
            int select = menu();
            if (select != 0 && select != 7 && m_fname == nullptr) {
                select = 7;
            }
            if (select == 1) {
                cout << "\n****List Items****" << endl;
                int numListed = list();
                if (numListed > 0) {
                    cout << "Enter row number to display details or <ENTER> to continue:\n> ";
                    cin.ignore();
                    if (cin.peek() != '\n') {
                        int rowNum = ut.getint(1, numListed);
                        m_products[rowNum - 1]->linear(false);
                        cout << *m_products[rowNum - 1];
                    }       
                    cout << endl;
                }
                else {
                    cout << "The list is empty!\n" << endl;
                }
            }
            else if (select == 2) {
                cout << "\n****Add Item****" << endl;
                if (m_numProducts < sdds_max_num_items) {
                    cout << "1- Perishable\n2- Non-Perishable\n-----------------\n0- Exit" << endl;
                    int choice = ut.getint(0, 2, "> ");
                    if (choice == 1 || choice == 2) {                        
                        //create pointer for temp iProduct
                        iProduct* temp;
                        if (choice == 1) {  //allocate mem for temp based on user choice
                            temp = new Perishable();
                        }
                        else {
                            temp = new Item();
                        }
                        int rSKU = temp->readSku(cin);
                        int foundSKU = search(rSKU);
                        if (foundSKU != -1) {
                            cout << "Sku: " << rSKU << " is already in the system, try updating quantity instead.\n" << endl;
                            delete temp;
                        }
                        else {
                            temp->read(cin);
                            cout << endl;
                            if (temp) {
                                int openIndex = findOpenIndex();                                
                                m_products[openIndex] = temp;
                                m_numProducts++;
                            }
                            else {
                                temp->display(cout);
                                delete temp;
                            }
                        }
                    }
                    else if (choice == 0) {
                        cout << "Aborted\n";
                    }
                    else {
                        cout << "Something went wrong with reading your choice :( Please contact support." << endl;
                    }
                }
                else {
                    cout << "Database full!" << endl;
                }
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
                cout << "\n****New/Open Aid Database****" << endl;
                cout << "Enter file name: ";
                load();
                cout << m_numProducts << " records loaded!\n" << endl;
            }
            else {
                exit = true;
                save();
                cout << "Exiting Program!" << endl;
            }
        } while (!exit);
    }
}
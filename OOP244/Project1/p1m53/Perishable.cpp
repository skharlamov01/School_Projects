/*Final Project Milestone 53
Module : Perishable
Filename : Perishable.cpp
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/08
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <cstring>  //using strlen for m_handling check
#include "Perishable.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
    Perishable::Perishable() : Item()
    {
        m_handling = nullptr;
    }
    Perishable::Perishable(const Perishable& item) : Item(item)
    {
        m_expiry = item.m_expiry;
        ut.alocpy(m_handling, item.m_handling);
    }
    Perishable& Perishable::operator=(const Perishable& item)
    {
        if (this != &item) {
            ut.alocpy(m_handling, item.m_handling);
            m_expiry = item.m_expiry;
            Item::operator=(item);
        }
        return *this;
    }
    Perishable::~Perishable()
    {
        delete[]m_handling;
        m_handling = nullptr;
    }
    Perishable::operator bool() const
    {
        return m_state && m_sku > 0;
    }
    const Date& Perishable::expiry() const
    {
        return m_expiry;
    }
    int Perishable::readSku(istream& istr)
    {
        int sku = 0;
        sku = ut.getint(10000, 39999, "SKU: ");
        m_sku = sku;
        return sku;
    }
    ofstream& Perishable::save(ofstream& ofstr) const
    {
        Item::save(ofstr);
        ofstr << '\t';
        if (m_handling != nullptr) {
            ofstr << m_handling;
        }
        Date expiry(m_expiry);
        expiry.formatted(false);
        ofstr << "\t" << expiry;
        return ofstr;
    }
    ifstream& Perishable::load(ifstream& ifstr)
    {
        Item::load(ifstr);
        if (ifstr.bad()) {
            m_state = "Input file stream read (perishable) failed!";
        }
        else {
            char tstr[1000];
            int date = 0;
            char b = ifstr.peek();
            if (isspace(b)) {
                ifstr.ignore();
                delete[] m_handling;
                m_handling = nullptr;
            }
            else {
                ifstr.get(tstr, 1000, '\t');
                ut.alocpy(m_handling, tstr);
                ifstr.ignore();
            }
            ifstr >> date;
            int year = date / 10000;
            date -= year * 10000;
            year += 2000;
            int month = date / 100;
            int day = date - month * 100;
            Date temp(year, month, day);
            m_expiry = temp;
            ifstr.ignore();
        }
        return ifstr;
    }
    ostream& Perishable::display(ostream& ostr) const
    {
            if (!m_state) {
                ostr << m_state;
            }
            else if (linear()) {
                Item::display(ostr);
                if (m_handling != nullptr && strlen(m_handling) > 0) {
                    ostr << '*';
                }
                else {
                    ostr << ' ';
                }
                ostr << m_expiry;
            }
            else {
                ostr << "Perishable ";
                Item::display(ostr);
                Date expiry(m_expiry);
                expiry.formatted(true);
                ostr << "Expiry date: " << expiry;
                if (m_handling != nullptr && strlen(m_handling) > 0) {
                    ostr << endl << "Handling Instructions: " << m_handling;
                }
                ostr << endl;
            }
        return ostr;
    }
    istream& Perishable::read(istream& istr)
    {
        if (istr.bad()) {
            m_state = "Perishable console date entry failed!";
        }
        else {
            Item::read(istr);
            delete[]m_handling;
            m_handling = nullptr;
            cout << "Expiry date (YYMMDD): ";
            istr >> m_expiry;
            istr.ignore();
            cout << "Handling Instructions, ENTER to skip: ";
            if (istr.peek() != '\n') {
                char tstr[1000];
                istr.get(tstr, 1000);
                ut.alocpy(m_handling, tstr);
            }
        }
        return istr;
    }
}
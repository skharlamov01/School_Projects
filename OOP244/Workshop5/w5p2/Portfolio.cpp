/*Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 20/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }

    Portfolio::operator const char* () const
    {
        return (const char*)m_stock;
    }

    Portfolio::operator char() const
    {
        return m_type;
    }

    Portfolio::operator bool() const
    {
        return m_type == 'G' || m_type == 'V' || m_type == 'I' ? true : false;
    }

    bool Portfolio::operator~() const
    {
        bool ret = false;
        if (m_value < 0) {
            ret = true;
        }
        return ret;
    }

    Portfolio& Portfolio::operator+=(double add)
    {
        if (*this && add > 0) {
            m_value += add;
        }
        return *this;
    }

    Portfolio& Portfolio::operator-=(double sub)
    {
        if (*this && sub > 0) {
            m_value -= sub;

        }
        return *this;
    }

    Portfolio& Portfolio::operator<<(Portfolio& port2)
    {
        if (*this && port2) {
            m_value += port2.m_value;
            port2.emptyPortfolio();
        }
        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& port2)
    {
        if (*this && port2) {
            port2.m_value += m_value;
            emptyPortfolio();
        }
        return *this;
    }

    double operator+(const Portfolio& leftp, const Portfolio& rightp)
    {
        double value = 0.00;
        if (leftp && rightp) {
            value = (double)leftp + (double)rightp;
        }
        return value;
    }

    double operator+=(double& add, const Portfolio& port1)
    {
        add += (double)port1;
        return add;
    }
}
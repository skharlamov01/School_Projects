/* Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 16/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
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
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    bool Flight::loadPeople(int tpeople) {
        bool retbool = false;
        if (tpeople + m_passengers > Boen747Capacity) {
            m_passengers = Boen747Capacity;
        }
        else if (tpeople + m_passengers < 0) {
            m_passengers = 0;
        }
        else {
            m_passengers += tpeople;
        }
        retbool = true;
        return retbool;
    }
    Flight::operator bool() const
    {
        return m_passengers > 0 && m_fuel >= 600 * m_passengers ? true: false;
    }
    Flight::operator int() const
    {
        return m_passengers;
    }
    Flight::operator double() const
    {
        return m_fuel;
    }
    Flight::operator const char*() const
    {
        return (const char*)m_title;
    }
    bool Flight::operator~() const
    {
        return m_passengers == 0 ? true : false;
    }
    Flight& Flight::operator=(Flight& f)
    {
        m_fuel = f.m_fuel;
        m_passengers = f.m_passengers;
        strcpy(m_title, f.m_title);
        f.emptyPlane();
        return *this;
    }
    Flight& Flight::operator=(int p)
    {
        if (p > 0 && p <= Boen747Capacity) {
            m_passengers = p;
        }
        return *this;
    }
    Flight& Flight::operator=(double f)
    {
        if (f > 0 && f <= FuelTankCapacity) {
            m_fuel = f;
        }
        return *this;
    }
    Flight& Flight::operator+=(double fuel)
    {
        if (fuel > 0 && m_fuel < FuelTankCapacity) {
            m_fuel = m_fuel + fuel > FuelTankCapacity ? FuelTankCapacity : m_fuel + fuel;
        }
        return *this;
    }
    Flight& Flight::operator+=(int p)
    {
        if (p > 0 && m_passengers < Boen747Capacity) {
            m_passengers = m_passengers + p > Boen747Capacity ? Boen747Capacity : m_passengers + p;
        }
        return *this;
    }
    Flight& Flight::operator-=(double fuel)
    {
        if (fuel > 0) {
            m_fuel = m_fuel - fuel < 0 ? 0 : m_fuel - fuel;
        }
        return *this;
    }
    Flight& Flight::operator-=(int passengers)
    {
        if (passengers > 0) {
            m_passengers = m_passengers - passengers < 0 ? 0 : m_passengers - passengers;
        }
        return *this;
    }
    Flight& Flight::operator<<(Flight& f)
    {
        int diff = 0;
        if (this && f) {
            if (m_passengers < Boen747Capacity) {
                diff = Boen747Capacity - m_passengers;
                this->loadPeople(diff);
                f.loadPeople(-diff);
            }
        }
        return *this;
    }
    Flight& Flight::operator>>(Flight& f)
    {
        int diff = 0;
        if (this && f) {
            if (f.m_passengers < Boen747Capacity) {
                diff = Boen747Capacity - f.m_passengers;
                f.loadPeople(diff);
                this->loadPeople(-diff);
            }
        }
        return *this;
    }
    int operator+(const Flight& f1, const Flight& f2)
    {
        int sum = 0;
        if (f1 && f2) {
            sum = (int)f1 + (int)f2;
        }
        return sum;
    }
    int operator+=(int& num, const Flight& f1)
    {
        num += (int)f1;
        return num;
    }
}
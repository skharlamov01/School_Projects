/*Workshop 6
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include "Autoshop.h"
using namespace std;

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(ostream& out) const
	{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (const auto vehicle : m_vehicles) {
			vehicle->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop()
	{
		for (auto itr : m_vehicles) {
			delete itr;
		}
	}
}
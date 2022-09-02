/*Workshop 6
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Car.h"
#include "Racecar.h"

namespace sdds
{
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto vehicle : m_vehicles) {
				if (test(vehicle)) {
					vehicles.push_back(vehicle);
				}
			}
		}
		void display(std::ostream& out) const;
		~Autoshop();
	};
}
#endif // !SDDS_AUTOSHOP_H

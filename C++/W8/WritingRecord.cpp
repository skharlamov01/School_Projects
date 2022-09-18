/*Workshop 8
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (std::size_t i = 0; i < emp.size(); i++) {
			for (std::size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					if (activeEmp.luhnCheck(emp[i].id)) {
						EmployeeWage* temp = new EmployeeWage(emp[i].name, sal[j].salary);
						try {
							temp->rangeValidator();
							activeEmp += temp;
							delete temp;
						}
						catch (std::string& e) {
							delete temp;
							throw e;
						}
					}
					else {
						throw std::string("*** Invalid SIN.");
					}
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers

		for (std::size_t i = 0; i < emp.size(); i++) {
			for (std::size_t j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					if (activeEmp.luhnCheck(emp[i].id)) {
						std::unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));
						try {
							temp->rangeValidator();
							activeEmp += std::move(temp);
						}
						catch (std::string& e) {
							throw e;
						}
					}
					else {
						throw std::string("*** Invalid SIN.");
					}
				}
			}
		}
		
		return activeEmp;
	}
}
/* Workshop 2 Part 1
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 24/01/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds
{
	struct Car {
		char license_plate[9];
		char* make_model;
		int time;
	};

	//Prints the first header and entry specifications
	void VBPLE_Title();

	void initialize(int allocSize);

	void deallocate(Car& C);

	bool read(Car& C);

	void print(const Car& C);

	void record(const Car& C);

	void endOfDay();
}

#endif // !SDDS_CAR_H

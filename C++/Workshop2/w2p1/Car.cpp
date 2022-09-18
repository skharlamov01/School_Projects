/* Workshop 2 Part 1
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 24/01/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Car.h"
#include "cStrTools.h"
using namespace std;

namespace sdds
{
	int num_cars;
	int arr_size;
	int alloc_size;
	Car* cars = nullptr;

	//Prints the first header and entry specifications
	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << endl;
		cout << "Enter the data in the following format:" << endl;
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl;
		cout << "Exit the program by entering the following:" << endl;
		cout << "X,<ENTER>" << endl;
	}

	void initialize(int allocSize) {
		num_cars = 0;
		arr_size = alloc_size = allocSize;
		cars = new Car[alloc_size];
	}

	void deallocate(Car& C) {
		delete[] C.make_model;
		C.make_model = nullptr;
	}

	bool read(Car& C) {
		bool flag = false;
		char cstring[61];
		read(cstring, 60, ',');
		if (strCmp(cstring, "X") != 0) {
			flag = true;
			C.make_model = new char[strLen(cstring) + 1];
			strCpy(C.make_model, cstring);
			read(C.license_plate, 8, ',');
			cin >> C.time;
		}
		return flag;
	}

	void print(const Car& C) {
		cout << C.time << ": " << C.make_model << "," << C.license_plate << endl;
	}

	void record(const Car& C) {
		if (num_cars >= arr_size) {
			Car* tmparr = new Car[arr_size + alloc_size];//a whole fuckton of resizing array bullshit
			for (int i = 0; i < arr_size; i++) {
				tmparr[i] = cars[i];
			}
			delete[] cars;
			arr_size += alloc_size;
			cars = tmparr;
		}
		cars[num_cars].make_model = C.make_model;
		strCpy(cars[num_cars].license_plate, C.license_plate);
		cars[num_cars].time = C.time;
		num_cars++;
	}

	void endOfDay() {
		for (int i = 0; i < num_cars; i++) {
			print(cars[i]);
			deallocate(cars[i]);
		}
		delete[] cars;
		cars = nullptr;
	}
}
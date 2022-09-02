/*Workshop 10 lab
Module : temps
Filename : temps.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/04/12
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H

#include <iostream>
#include "Collection.h"

namespace sdds
{
	template<class object>
	/*For the select function, each object with a class type needs to
	have an '==' operator overload that allows the class to be compared
	with another class of the same type. Similarly, each object needs to
	have an '=' operator overload that functions as a fool-proof
	assignment operator for the object.*/
	Collection<object> select(const object arr[], const int arr_size, const object& arr_search) {
		int numMatch = 0;	//counter for how many matches are found
		for (int i = 0; i < arr_size; i++) {	//first loop to determine amount of matches
			if (arr[i] == arr_search) {
				numMatch++;
			}
		}
		Collection<object>temp(numMatch);
		int collIndex = 0;	//index counter for the insertion into the collection
		for (int j = 0; j < arr_size; j++) {	//second loop to insert matches into collection
			if (arr[j] == arr_search) {
				temp[collIndex] = arr[j];
				collIndex++;
			}
		}
		return temp;
	};
	template<class object>
	/*for the printCollection function, an object of the class type
	needs to have a function called size() that returns the size of the
	array through which to loop. The object also needs to have a 
	'<<' operator override that defines the display of the object to 
	the output stream.*/
	void printCollection(const Collection<object>& coll, const char title[]) {
		std::cout << title << std::endl;
		for (unsigned i = 0; i < coll.size(); i++) {
			std::cout << coll[i] << std::endl;
		}
	};
}
#endif // !SDDS_TEMPS_H

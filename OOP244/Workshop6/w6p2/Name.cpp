/* Workshop 6 Part 2
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 05/03/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <string>	//for string class
#include <cstring>	//for strcpy
#include "Name.h"

using namespace std;

namespace sdds
{
	void Name::setEmpty()
	{
		first_name = nullptr;
		middle_name = nullptr;
		last_name = nullptr;
		/*if (middle_name != nullptr) {
			delete[] middle_name;
			middle_name = nullptr;
		}
		if (last_name != nullptr) {
			delete[] last_name;
			last_name = nullptr;
		}*/
	}
	Name::Name()
	{
		setEmpty();
	}
	Name::Name(const char* first)
	{
		strcpy(first_name, first);
		strcpy(middle_name, "");
		strcpy(last_name, "");
	}
	Name::Name(const char* first, const char* last)
	{
		strcpy(first_name, first);
		strcpy(last_name, last);
		strcpy(middle_name, "");
	}
	Name::Name(const char* first, const char* middle, const char* last)
	{
		strcpy(first_name, first);
		strcpy(middle_name, middle);
		strcpy(last_name, last);
	}
	Name::Name(const Name& name_copy)
	{
		if (name_copy) {
			first_name = new char[strlen(name_copy.first_name) + 1];
			strcpy(first_name, name_copy.first_name);
			if (name_copy.middle_name != nullptr) {
				middle_name = new char[strlen(name_copy.middle_name) + 1];
				strcpy(middle_name, name_copy.middle_name);
			}
			if (name_copy.last_name != nullptr) {
				last_name = new char[strlen(name_copy.last_name) + 1];
				strcpy(last_name, name_copy.last_name);
			}
		}
	}
	Name& Name::operator=(const Name& name_copy)
	{
		if (name_copy) {
			first_name = new char[strlen(name_copy.first_name) + 1];
			strcpy(first_name, name_copy.first_name);
			if (name_copy.middle_name != nullptr) {
				middle_name = new char[strlen(name_copy.middle_name) + 1];
				strcpy(middle_name, name_copy.middle_name);
			}
			if (name_copy.last_name != nullptr) {
				last_name = new char[strlen(name_copy.last_name) + 1];
				strcpy(last_name, name_copy.last_name);
			}
		}
		return *this;
	}
	Name::~Name()
	{
		delete[] first_name;
		//first_name = nullptr;
		if (middle_name != nullptr) {
			delete[] middle_name;
			//middle_name = nullptr;
		}
		if (last_name != nullptr) {
			delete[] last_name;
			//last_name = nullptr;
		}
		setEmpty();
	}
	Name::operator bool() const
	{
		return first_name != nullptr ? true : false;
	}
}
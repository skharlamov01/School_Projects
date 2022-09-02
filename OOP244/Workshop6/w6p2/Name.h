/* Workshop 6 Part 2
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 05/03/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_NAME_H
#define SDDS_NAME_H

namespace sdds
{
	class Name {
		char* first_name;
		char* middle_name;
		char* last_name;
		void setEmpty();
	public:
		//four constructors
		Name();
		Name(const char* first);
		Name(const char* first, const char* last);
		Name(const char* first, const char* middle, const char* last);
		//rule of three
		Name(const Name& name_copy);	//copy constructor
		Name& operator=(const Name& name_copy);	//assignment constructor
		~Name();	//deconstructor
		//
		Name& setShort(bool isAbbrev);
		Name& operator+=(const char* str);
		operator bool() const;
	};
	std::ostream& operator<<(std::ostream&, const Name& name);
	std::istream& operator>>(std::istream& istr, Name& name);
}
#endif // !SDDS_NAME_H

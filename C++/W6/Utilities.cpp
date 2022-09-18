/*Workshop 6
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/10
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <exception>
#include <cctype>
#include "Utilities.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(istream& istr)
	{
		char peek = istr.peek();
		while (isspace(peek)) {
			istr.ignore();
			peek = istr.peek();
		}
		if (istr.eof()) {
			return nullptr;
		}
		switch(peek) {
		case 'c':
		case 'C':
			return new Car(istr);
			break;
		case 'r':
		case 'R':
			return new Racecar(istr);
			break;
		default:
			string temp(1, peek);
			istr.ignore(50, '\n');
			throw invalid_argument(temp);
			break;
		}
	}
}
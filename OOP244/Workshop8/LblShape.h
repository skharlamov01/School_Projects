/*Workshop 8 lab
Module : LabelShape
Filename : LblShape.h
Version 1.0
Author : Sasha Kharlamov
Author ID : 150707214
Date : 2022/03/24
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape {
		char* m_label;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* str);
		~LblShape();
		LblShape(LblShape&) = delete;
		LblShape& operator=(LblShape&) = delete;
		void getSpecs(std::istream& istr);
	};
}
#endif // !SDDS_LBLSHAPE_H

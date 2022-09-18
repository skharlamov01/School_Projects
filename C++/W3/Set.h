/*Workshop 3
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/05
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_SET_H
#define SDDS_SET_H

#include "Collection.h"

namespace sdds
{
	template<typename T>
	class Set : public Collection<T, 100> {
	public:
		bool add(const T& item) {
			for (unsigned i = 0u; i < Set<T>::size(); i++) {
				if (Set<T>::operator[](i) == item) {
					return false;
				}
			}
			Collection<T, 100>::add(item);
			return true;
		}
	};
	template<>
	bool Set<double>::add(const double& item) {
		for (unsigned i = 0u; i < Set<double>::size(); i++) {
			if (std::fabs(Set<double>::operator[](i) - item) <= 0.01) {
				return false;
			}
		}
		Collection<double, 100>::add(item);
		return true;
	}
}
#endif // !SDDS_SET_H

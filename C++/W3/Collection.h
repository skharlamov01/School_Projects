/*Workshop 3
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/05
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include "Pair.h"

namespace sdds
{
	template <typename T, unsigned capacity>
	class Collection {
		T m_array[capacity]{};
		unsigned m_currentSize;
		static T m_dummy;
	public:
		Collection() : m_currentSize{ 0u } {}
		unsigned size() const {
			return m_currentSize;
		}
		std::ostream& display(std::ostream& ostr = std::cout) const{
			ostr << "----------------------\n| Collection Content |\n----------------------" << std::endl;
			for (unsigned i = 0; i < m_currentSize; i++) {
				ostr << m_array[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
			return ostr;
		}
		virtual bool add(const T& item) {
			if (m_currentSize == capacity) {
				return false;
			}
			else {
				m_array[m_currentSize] = item;
				m_currentSize++;
				return true;
			}
		}
		T& operator[](unsigned i) {
			return i < m_currentSize ? m_array[i] : m_dummy;
		}
		~Collection() {}
	};
	template<typename T, unsigned capacity>
	T Collection<T, capacity>::m_dummy = T();
	template<>
	Pair Collection<Pair, 100>::m_dummy{ "No Key", "No Value" };
}
#endif // !SDDS_COLLECTION_H

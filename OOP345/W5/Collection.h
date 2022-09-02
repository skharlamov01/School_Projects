/*Workshop 5
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/20
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>
#include <exception>
namespace sdds
{
	template <typename T>
	class Collection {
		std::string m_name{};
		T* m_items = nullptr;
		size_t m_arrSize = 0;
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection() = default;
		Collection(const std::string& name) : m_name{ name }, m_arrSize{ 0 } {
			m_items = nullptr;
			m_observer = nullptr;
		}
		Collection& operator=(Collection&& C) {
			if (this != &C) {
				m_name = C.m_name;
				delete[]m_items;
				m_items = C.m_items;
				C.m_items = nullptr;
				m_arrSize = C.m_arrSize;
				m_observer = C.m_observer;
			}
			return *this;
		}
		Collection(Collection&& C) {
			operator=(C);
		}
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() { delete[]m_items; }
		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_arrSize;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < m_arrSize; i++) {	//loop to make sure there are no copies
				if (m_items[i].title() == item.title())
					return *this;
			}
			if (m_arrSize > 0) {
				T* newItems;
				newItems = new T[++m_arrSize];
				for (size_t i = 0; i < m_arrSize - 1; i++) {
					newItems[i] = m_items[i];
				}
				delete[] m_items;
				newItems[m_arrSize - 1] = item;
				m_items = newItems;
			}
			else {
				m_items = new T[++m_arrSize];
				m_items[m_arrSize - 1] = item;
			}
			if (m_observer != nullptr) {
				m_observer(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= m_arrSize) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_arrSize) + "] items.");
			}
			else 
				return m_items[idx];
		}
		T* operator[](const std::string& title) const {
			for (auto i = 0u; i < m_arrSize; i++) {
				if (m_items[i].title() == title) {
					return &m_items[i];
				}
			}
			return nullptr;
		}
	};
	template <typename T>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T>& coll) {
		for (auto i = 0u; i < coll.size(); i++) {
			ostr << coll[i];
		}
		return ostr;
	}
}
#endif // !SDDS_COLLECTION_H

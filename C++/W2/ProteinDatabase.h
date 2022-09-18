/*Workshop 2
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/05/29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_PROTEIN_H
#define SDDS_PROTEIN_H

#include <string>
#include <utility>

namespace sdds
{
	class ProteinDatabase {
		size_t m_numStrs{};
		std::string* m_sequences{};
	public:
		ProteinDatabase() = default;
		ProteinDatabase(const std::string filename);
		ProteinDatabase(const ProteinDatabase& obj2);
		ProteinDatabase& operator=(const ProteinDatabase& obj2);
		ProteinDatabase(ProteinDatabase&& obj2) {
			*this = std::move(obj2);
		};
		ProteinDatabase& operator=(ProteinDatabase&& obj2);
		~ProteinDatabase();
		void cleanString(int index);
		size_t size() const;
		std::string operator[](size_t ind) const;
	};
}
#endif // !SDDS_PROTEIN_H

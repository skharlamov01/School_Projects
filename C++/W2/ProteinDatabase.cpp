/*Workshop 2
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/05/29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <fstream>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds
{
	ProteinDatabase::ProteinDatabase(const string filename)
	{
		int numSqnc = 0;
		ifstream fin(filename);
		if (fin) {	//checking if file opened properly
			char c;
			while (fin.good()) {	//first loop to count how many sequences
				fin >> c;
				if (c == '>') {
					numSqnc++;
				}
			}
			m_sequences = new string[numSqnc];	//allocating for counted sequences
			fin.clear();
			fin.seekg(0);	//rewinding to start of file
			fin.ignore(250, '\n');	//to ignore first heading
			while (!fin.eof()) {	//reading the sequences into array
				static int i = 0;
				getline(fin, m_sequences[i], '>');
				cleanString(i);
				i++;
				fin.ignore(250, '\n');
			}
			m_numStrs = numSqnc;
			fin.close();
		}
	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& obj2)
	{
		delete[]m_sequences;
		m_sequences = new string[obj2.m_numStrs];
		for (unsigned i = 0; i < obj2.m_numStrs; i++) {
			m_sequences[i] = obj2.m_sequences[i];
		}
		m_numStrs = obj2.m_numStrs;
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& obj2)
	{
		if (this != &obj2) {
			delete[]m_sequences;
			m_sequences = new string[obj2.m_numStrs];
			for (unsigned i = 0; i < obj2.m_numStrs; i++) {
				m_sequences[i] = obj2.m_sequences[i];
			}
			m_numStrs = obj2.m_numStrs;
		}
		return *this;
	}
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& obj2) {
		if (this != &obj2) {
			delete[] m_sequences;
			m_sequences = obj2.m_sequences;
			obj2.m_sequences = nullptr;
			m_numStrs = obj2.m_numStrs;
			obj2.m_numStrs = 0;
		}
		return *this;
	}
	ProteinDatabase::~ProteinDatabase()
	{
		delete[]m_sequences;
		m_sequences = nullptr;
	}
	size_t ProteinDatabase::size() const
	{
		return m_numStrs;
	}
	string ProteinDatabase::operator[](size_t ind) const
	{
		if (ind >= 0 && ind < m_numStrs) {
			return m_sequences[ind];
		}
		else {
			return string();
		}
	}
	void ProteinDatabase::cleanString(int index)
	{
		int pos;
		while (m_sequences[index].find('\n') != string::npos) {
			pos = m_sequences[index].find('\n');
			m_sequences[index].erase(pos, 1);
		}
	}
}
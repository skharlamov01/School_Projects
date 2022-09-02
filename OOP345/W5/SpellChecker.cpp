/*Workshop 5
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/19
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;
namespace sdds
{
	string SpellChecker::cleanString(string str)
	{
		if (isspace(str[0])) {	//check if any spaces in front
			//clean all front spaces
			int i = 0;
			while (isspace(str[i])) {
				str.erase(i, 1);
			}
		}
		if (isspace(str[str.length() - 1])) {	//check if any spaces in back
			//clean all back spaces
			int i = str.length() - 1;
			while (isspace(str[i])) {
				str.erase(i--, 1);
			}
		}
		return str;
	}
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream fin(filename);
		char temp[51];
		if (fin) {
			int i = 0;
			do {
				fin.getline(temp, 50, ' ');
				m_badWords[i] = cleanString(string(temp));
				fin.getline(temp, 50, '\n');
				m_goodWords[i++] = cleanString(string(temp));
			} while (i < 6);
		}
		else {
			throw "Bad file name!";
		}
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (int i = 0; i < 6; i++) {
			while (text.find(m_badWords[i]) != string::npos) {
				int pos = text.find(m_badWords[i]);
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				m_replaceNum[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		for (int i = 0; i < 6; i++) {
			out << setw(15) << right << m_badWords[i] << ": " << left << m_replaceNum[i] << " replacements" << endl;
		}
	}
}
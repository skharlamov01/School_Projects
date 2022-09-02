/*Workshop 5
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/20
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds
{
	Movie::Movie(const std::string& strMovie)
	{
		string temp;
		try {
			int lpos = 0;	//leftmost position of substr
			int rpos = 0;	//rightmost position of substr
			rpos = strMovie.find(",", lpos);
			temp = strMovie.substr(lpos, rpos);
			cleanString(temp);
			m_title = temp;	// finished block for reading in title
			lpos = ++rpos;
			rpos = strMovie.find(",", lpos);
			temp = strMovie.substr(lpos, rpos - lpos);
			m_year = stoi(temp);	//finished block of reading in year
			lpos = ++rpos;
			rpos = strMovie.find("\n", lpos);
			temp = strMovie.substr(lpos, rpos - lpos);
			cleanString(temp);
			m_desc = temp;	//finished block of reading in description
		}
		catch (...) {
			cout << "DEBUG: Error in overloaded movie reading constructor!" << endl;
		}
	}
	void Movie::cleanString(std::string& str)
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
	}
	std::ostream& operator<<(std::ostream& ostr, const Movie& movie)
	{
		ostr << setw(40) << right << movie.m_title << " | ";
		ostr << setw(4) << movie.m_year << " | ";
		ostr << left << movie.m_desc << endl;
		return ostr;
	}
	const std::string& Movie::title() const
	{
		return m_title;
	}
	Movie& Movie::operator=(const Movie& m2)
	{
		m_year = m2.m_year;
		m_title = m2.m_title;
		m_desc = m2.m_desc;
		return *this;
	}
}
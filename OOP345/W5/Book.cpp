/*Workshop 5
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/06/17
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <iomanip>
#include <cctype>
#include "Book.h"

using namespace std;
namespace sdds
{
	Book::Book(const string& strBook)
	{
		string temp;
		try {
			int lpos = 0;	//leftmost position of substr
			int rpos = 0;	//rightmost position of substr
			rpos = strBook.find(",", lpos);
			temp = strBook.substr(lpos, rpos);
			cleanString(temp);
			m_author = temp;	//finished block of reading in author
			lpos = ++rpos;
			rpos = strBook.find(",", lpos);
			temp = strBook.substr(lpos, rpos - lpos);
			cleanString(temp);
			m_title = temp;	//finished block of reading in title
			lpos = ++rpos;
			rpos = strBook.find(",", lpos);
			temp = strBook.substr(lpos, rpos - lpos);
			cleanString(temp);
			m_country = temp;	//finished block of reading in country
			lpos = ++rpos;
			rpos = strBook.find(",", lpos);
			temp = strBook.substr(lpos, rpos - lpos);
			m_price = stod(temp);	//finished block of reading in price
			lpos = ++rpos;
			rpos = strBook.find(",", lpos);
			temp = strBook.substr(lpos, rpos - lpos);
			m_pubYear = stoi(temp);	//finished block of reading in year
			lpos = ++rpos;
			rpos = strBook.find("\n", lpos);
			temp = strBook.substr(lpos, rpos - lpos);
			cleanString(temp);
			m_desc = temp;	//finished block of reading in description
		}
		catch (...) {
			cout << "DEBUG: Error in overloaded constructor read!" << endl;
		}
	}
	const string& Book::title() const
	{
		return m_title;
	}
	const string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_pubYear;
	}
	double& Book::price()
	{
		return m_price;
	}
	Book& Book::operator=(const Book& bk2)
	{
		m_author = bk2.m_author;
		m_title = bk2.m_title;
		m_country = bk2.m_country;
		m_desc = bk2.m_desc;
		m_pubYear = bk2.m_pubYear;
		m_price = bk2.m_price;
		return *this;
	}
	void Book::cleanString(std::string& str)
	{
		if (isspace(str[0])) {	//check if any spaces in front
			//clean all front spaces
			int i = 0;
			while (isspace(str[i])) {
				str.erase(i, 1);
			}
		}
		if (isspace(str[str.length() - 1])){	//check if any spaces in back
			//clean all back spaces
			int i = str.length() - 1;
			while (isspace(str[i])) {
				str.erase(i--, 1);
			}
		}	
	}
	ostream& operator<<(ostream& ostr, const Book& book)
	{
		cout.setf(ios::right);
		cout << setw(20) << book.m_author << " | ";
		cout << setw(22) << book.m_title << " | ";
		cout << setw(5) << book.m_country << " | ";
		cout << setw(4) << book.m_pubYear << " | ";
		cout << setw(6) << fixed << setprecision(2) << book.m_price << " | ";
		cout << left << book.m_desc << endl;
		return ostr;
	}
}
// Name: Sasha Kharlamov
// Seneca Student ID: 150707214
// Seneca email: skharlamov@myseneca.ca
// Date of completion: 2022/07/29
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <exception>
#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delimiter = ',';
	void Utilities::cleanString(std::string& str)
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
	void Utilities::setFieldWidth(std::size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		if (str[next_pos] == getDelimiter()) {
			more = false;
			throw std::exception();
		}
		else {
			int i = next_pos;
			int tokLength = 0;
			while (str[i] != getDelimiter() && str[i] != '\0') {
				i++;
				tokLength++;
			}
			std::string token = str.substr(next_pos, tokLength);
			cleanString(token);
			next_pos += tokLength + 1;
			more = true;
			if (token.length() > getFieldWidth())
				setFieldWidth(token.length());
			if (str[i] == '\0')
				more = false;
			return token;
		}
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		Utilities::m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}
// Name: Sasha Kharlamov
// Date of completion: 2022/08/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTIL_H
#define SDDS_UTIL_H

#include <iostream>
#include <exception>

namespace sdds
{
	class Utilities {
		int m_widthField{ 1 };
		static char m_delimiter;
	public:
		void cleanString(std::string& str);
		void setFieldWidth(std::size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !SDDS_UTIL_H

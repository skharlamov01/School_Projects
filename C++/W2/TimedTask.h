/*Workshop 2
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/05/29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#ifndef SDDS_TIMED_H
#define SDDS_TIMED_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds
{
	struct Task {
		std::string m_name;
		std::string m_units;
		std::chrono::steady_clock::duration m_duration;
	};
	class TimedTask {
		int m_numRecords;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_stopTime;
		Task m_event[10]{};
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* taskName);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedTask obj);
	};
}
#endif // !SDDS_TIMED_H

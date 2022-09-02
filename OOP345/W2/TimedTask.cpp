/*Workshop 2
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/05/29
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */

#include <iomanip>	//for formatting in friend operator
#include "TimedTask.h"

using namespace std;

namespace sdds
{
	TimedTask::TimedTask()
	{
		m_numRecords = 0;
	}
	void TimedTask::startClock()
	{
		m_startTime = chrono::steady_clock::now();
	}
	void TimedTask::stopClock()
	{
		m_stopTime = chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* taskName)
	{
		string str_taskName(taskName);
		auto dur = chrono::duration_cast<chrono::nanoseconds>(m_stopTime - m_startTime);
		if (m_numRecords < 10) {
			m_event[m_numRecords].m_name = str_taskName;
			m_event[m_numRecords].m_units = "nanoseconds";
			m_event[m_numRecords].m_duration = dur;
			m_numRecords++;
		}
	}
	ostream& operator<<(ostream& ostr, const TimedTask obj)
	{
		ostr << "--------------------------\nExecution Times:\n--------------------------" << endl;
		for (int i = 0; i < obj.m_numRecords; i++) {
			ostr << setw(21) << left << obj.m_event[i].m_name 
				<< setw(13) << right << obj.m_event[i].m_duration.count() <<
				" " << obj.m_event[i].m_units << endl;
		}
		ostr << "--------------------------" << endl; 
		return ostr;
	}
}
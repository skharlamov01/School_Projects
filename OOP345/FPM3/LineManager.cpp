// Name: Sasha Kharlamov
// Seneca Student ID: 150707214
// Seneca email: skharlamov@myseneca.ca
// Date of completion: 2022/08/09
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		try {
			std::ifstream fin(file);
			char cStr[51];
			std::string str;
			std::vector<std::string> nextStations;	//vector for holding next station names. Used in finding the first workstation
			while (fin.getline(cStr, 50, '\n')) {
				str.assign(cStr);
				if (str.find('|') != std::string::npos) {	//extract first station name if there's a delimiter
					nextStations.push_back(str.substr(str.find('|') + 1, str.length() - str.find('|')));	//add next station/station name after the '|' to premade list of next stations
					str = str.substr(0, str.find('|'));	//turn str into name of station only
				}
				else {
					nextStations.push_back(std::string("null"));
				}
				auto match = std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
					return str == ws->getItemName();
					});
				m_activeLine.push_back(*match);
			}
			//find NextStation pointers
			// !!THIS ONLY WORKS BECAUSE BOTH m_activeLine AND nextStations ARE LOADED IN THE SAME ORDER FROM FILE!!
			int i = 0;	//manual index to have nextStation vector follow m_activeLine vector by index in for_each
			std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
				if (nextStations[i] != "null") {	//only searching for iter if its not last station in line order which is coded to be string "null" if found in file
					auto iter = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* nWs) {
						return nextStations[i] == nWs->getItemName();
						});
					ws->setNextStation(*iter);	//add pointer of found element to current m_pNextStation
				}
				i++;	//iterating the manual index to ensure nextStations follows m_activeLine
				});
			//find first station
			std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
				if (std::none_of(nextStations.begin(), nextStations.end(), [&](std::string s) { return ws->getItemName() == s; })) {
					m_firstStation = ws;
				}
				});
		}
		catch (...) {
			std::cerr << "Something went wrong in the LineManager constructor!" << std::endl;
			throw std::exception();
		}
	}
	void LineManager::reorderStations()
	{
		//find the index of the m_firstStation* and swap it with first index
		//this ensures that the for loop works its way in order from the first station down
		auto first = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* fStat) {
			return fStat == m_firstStation;
			});
		std::swap(*first, m_activeLine.front());
		for (size_t i = 0; i < m_activeLine.size(); i++) {	//iterate through all elements starting at top
				if (m_activeLine[i]->getNextStation() != nullptr && m_activeLine[i]->getNextStation() != m_activeLine[i + 1]) {	//check if station[i] next station ptr == next station address in vector
					auto iter = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {	//find the station that matches next station ptr for station[i]
						return m_activeLine[i]->getNextStation() == ws;
						});
					std::swap(m_activeLine[i + 1], *iter);	//swap found station address with next station in vector
				}
			//}
		}
	}
	bool LineManager::run(std::ostream& os)
	{
		bool areOrdersFilled = false;
		static int iteration = 1;	//to keep track of current iteration of run()
		os << "Line Manager Iteration: " << iteration << std::endl;
		if (g_pending.size() > 0) {	//only proceed with moving orders from pending if there are orders to be done
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		for (auto station: m_activeLine) {	//each station on the line executes one fill() order
			station->fill(os);
		}
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
			if (ws->getOrderListSize() > 0)	ws->attemptToMoveOrder();
			});
		areOrdersFilled = std::all_of(m_activeLine.begin(), m_activeLine.end(), [](Workstation* ws) {
			return ws->getOrderListSize() == 0;
			});
		iteration++;
		return areOrdersFilled;
	}
	void LineManager::display(std::ostream& os) const
	{
		for (auto station : m_activeLine) {
			station->display(os);
		}
	}
}
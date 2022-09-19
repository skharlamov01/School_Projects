/* Workshop 4 Part 2
Name: Sasha Kharlamov
Date: 13/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>	//for .display formatting
#include <cstring>	//for strlen and strcpy
#include "Robot.h"
using namespace std;

namespace sdds
{
	void Robot::setEmpty() {
		name = nullptr;
		location = nullptr;
		weight = 0.0f;
		width = 0.0f;
		height = 0.0f;
		rspeed = 0.0f;	//speed cannot be negative, thus being the default
		deployed = false;
	}
	Robot::Robot() {	//empty state constructor
		name = nullptr;
		location = nullptr;
		weight = 0.0f;
		width = 0.0f;
		height = 0.0f;
		rspeed = 0.0f;	//speed cannot be negative, thus being the default
		deployed = false;
	}
	Robot::Robot(const char* tname, const char* tlocation, double tweight, double twidth, double theight, double tspeed, bool tdeploy) {
		if (tname != nullptr && tlocation != nullptr && tweight > 0 && twidth > 0 && theight > 0 && tspeed > 0) {
			name = new char[strlen(tname) + 1];
			strcpy(name, tname);
			location = new char[strlen(tlocation) + 1];
			strcpy(location, tlocation);
			weight = tweight;
			width = twidth;
			height = theight;
			rspeed = tspeed;
			deployed = tdeploy;
		}
		else {	//if any values given are invalid, set the robot to empty state
			setEmpty();
		}
	}
	Robot::~Robot() {
		delete[] name;
		delete[] location;
		name = nullptr;
		location = nullptr;
	}
	Robot& Robot::set(const char* tname, const char* tlocation, double tweight, double twidth, double theight, double tspeed, bool tdeploy) {
		if (tname != nullptr && tlocation != nullptr && tweight > 0 && twidth > 0 && theight > 0 && tspeed > 0) {
			name = new char[strlen(tname) + 1];
			strcpy(name, tname);
			location = new char[strlen(tlocation) + 1];
			strcpy(location, tlocation);
			weight = tweight;
			width = twidth;
			height = theight;
			rspeed = tspeed;
			deployed = tdeploy;
		}
		else {	//if any values given are invalid, set the robot to empty state
			setEmpty();
		}
		return *this;
	}
	void Robot::setLocation(const char* tlocation) {
		if (tlocation != nullptr) {
			location = new char[strlen(tlocation) + 1];
			strcpy(location, tlocation);
		}
		else {
			cout << "Location given is invalid!" << endl;
		}
	}
	void Robot::setDeployed(bool tdeploy) {
		deployed = tdeploy;
	}
	char* Robot::getName() const
	{
		return name;
	}
	char* Robot::getLocation() const
	{
		return location;
	}
	double Robot::speed() const
	{
		return rspeed;
	}
	bool Robot::isDeployed() const
	{
		return deployed == true ? true: false;
	}
	bool Robot::isValid() const
	{
		if (name != nullptr && location != nullptr && weight > 0 && width > 0 && height > 0 && rspeed > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void Robot::display() const
	{
		cout.setf(ios::left);
		cout << "| " << setw(10) << name;
		cout << " | " << setw(15) << location;
		cout.unsetf(ios::left);
		cout << " | " << setw(6) << fixed << setprecision(1) << weight;
		cout << " | " << setw(6) << fixed << setprecision(1) << width;
		cout << " | " << setw(6) << fixed << setprecision(1) << height;
		cout << " | " << setw(6) << fixed << setprecision(1) << rspeed;
		cout << " | ";
		cout.setf(ios::left);
		if (deployed) {
			cout << setw(8) << "YES";
		}
		else {
			cout << setw(8) << "NO";
		}
		cout.unsetf(ios::left);
		cout << " |" << endl;
	}
	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int validnum = -1;	//default return value
		int num_deployed = 0;	//total number of deployed robots
		int fast_index = 0; //index of the fastest found robot

		/*printing the header for the report*/
		cout << "                        ------ Robot Control Room -----" << endl;
		cout << "                    ---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;

		/*loop to print all valid robots*/
		for (int i = 0; i < num_robots && validnum == -1; i++) {
			if (robot[i].isValid()) {
				robot[i].display();
				if (robot[i].isDeployed()) {
					num_deployed++;
					if (robot[i].speed() > robot[fast_index].speed()) {
						fast_index = i;
					}
				}
			}
			else {
				validnum = i;
			}
		}
		if (validnum != -1) {	//if any invalid robots were found, interrupt display to return index of broken robot
			return validnum;
		}
		/*summary overview */
		cout << "|=============================================================================|" << endl;
		cout << "| SUMMARY:                                                                    |" << endl;
		cout << "| ";
		cout.setf(ios::left);
		cout << setw(2) << num_deployed << " robots are deployed." << endl;
		cout << "| The fastest robot is:                                                       |" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		robot[fast_index].display();
		cout << "|=============================================================================|" << endl;

		return validnum;
	}
}
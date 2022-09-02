/* Workshop 3 Part 1
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 02/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Train.h"
using namespace std;
using namespace sdds;

namespace sdds
{
	Train::Train() {	//settings for a safe empty state for instance of Train
		name[MAX_NAME_LEN] = { '\0' };	//no name assigned to the train
		num_people = -1;	//train cannot have negative passengers, therefore identifying it as an empty instance
		speed = -1.0f;	//train cannot be moving at negative speed, therefore identifying it as an empty instance
	}
	void Train::set(const char* tname, int tpeople, double tspeed) {
		if ((tname != nullptr && strlen(tname) > 0) && (tpeople >= 0 && tpeople <= MAX_PEOPLE) && (tspeed >= 0 && tspeed <= MAX_SPEED)) {	//data only replaces empty if all values are valid
			strncpy(name, tname, MAX_NAME_LEN);
			num_people = tpeople;
			speed = tspeed;
		}
		else {	//setting train to default empty if any values given are invalid
			name[MAX_NAME_LEN] = { '\0' };	//no name assigned to the train
			num_people = -1;	//train cannot have negative passengers, therefore identifying it as an empty instance
			speed = -1.0f;	//train cannot be moving at negative speed, therefore identifying it as an empty instance
		}
	}
	int Train::getNumberOfPeople() const{
		return num_people;
	}
	const char* Train::getName() const{
		return name;
	}
	double Train::getSpeed() const{
		return speed;
	}
	bool Train::isSafeEmpty() const{
		if (num_people == -1 && speed == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void Train::display() const{
		if (isSafeEmpty()) {
			cout << "Safe Empty State!" << endl;
		}
		else {
			cout << "NAME OF THE TRAIN : " << name << endl;
			cout << "NUMBER OF PEOPLE  : " << num_people << endl;
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "SPEED             : " << speed << " km/h" << endl;
		}
	}
	bool Train::loadPeople(int tpeople) {
		bool retbool = false;
		if (!isSafeEmpty()) {
			if (tpeople + num_people > MAX_PEOPLE) {
				num_people = MAX_PEOPLE;
			}
			else if (tpeople + num_people < 0) {
				num_people = 0;
			}
			else {
				num_people += tpeople;
			}
			retbool = true;
		}
		return retbool;
	}
	bool Train::changeSpeed(double tspeed) {
		bool retbool = false;
		if (!isSafeEmpty()) {
			if (tspeed + speed > MAX_SPEED) {
				speed = MAX_SPEED;
			}
			else if (tspeed + speed < 0) {
				speed = 0;
			}
			else {
				speed += tspeed;
			}
			retbool = true;
		}
		return retbool;
	}
	int transfer(Train& train1, Train& train2) {
		int diff = -1;
		int t1people = train1.getNumberOfPeople();
		if (train1.isSafeEmpty() == false && train2.isSafeEmpty() == false) {	//making sure neither train is in a safe empty state
			if (t1people >= MAX_PEOPLE) {	//checking if train is already full, and returning '0 people transferred' if true
				diff = 0;
			}
			else {
				diff = MAX_PEOPLE - t1people;
				train1.loadPeople(diff);
				train2.loadPeople(-diff);
			}
		}
		return diff;
	}
}
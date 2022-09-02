/* Workshop 3 Part 1
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 02/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME_LEN = 20;
	const int MAX_PEOPLE = 1000;
	const int MAX_SPEED = 320;

	class Train {
		char name[MAX_NAME_LEN + 1];
		int num_people;
		double speed;
	public:
		Train();
		void set(const char*, int, double);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		bool loadPeople(int tpeople);
		bool changeSpeed(double tspeed);
		void display() const;
	};
	int transfer(Train& train1, Train& train2);
}
#endif // !SDDS_TRAIN_H

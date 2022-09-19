/* Workshop 4 Part 2
Name: Sasha Kharlamov
Date: 13/02/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds
{
	class Robot {
		char* name;
		char* location;
		double weight;
		double width;
		double height;
		double rspeed;
		bool deployed;
	public:
		/*constructors/destructors*/
		Robot();
		Robot(const char* tname, const char* tlocation, double tweight, double twidth, double theight, double tspeed, bool tdeploy);
		~Robot();
		/*modifiers*/
		void setEmpty();
		Robot& set(const char* tname, const char* tlocation, double tweight, double twidth, double theight, double tspeed, bool tdeploy);
		void setLocation(const char* tlocation);
		void setDeployed(bool tdeploy);
		/*queries*/
		char* getName() const;
		char* getLocation() const;
		bool isDeployed() const;
		bool isValid() const;
		double speed() const;
		void display() const;
	};
	int conrtolRooomReport(const Robot robot[], int num_robots);
}

#endif // !SDDS_ROBOT_H

/* Workshop 1 Part 2
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 16/01/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Phone.h"
#include "cStrTools.h"
using namespace std;

namespace sdds
{
	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName) {
		char input[51] = {""};	//stores user input to search for
		bool flag = true;	//flag used to exit the menu when user is done
		FILE* dir = NULL;	//pointer to store the phone directory file
		char fname[51];	//name scanned from file
		char tname[51];	//stores the properly capitalized name from file
		char area[4];	//stores phone area code
		char prefix[4];	//stores the phone prefix no.
		char number[5];	//stores the last 4 digits of phone no.

		cout << programTitle << " phone directory search" << endl;
		cout << "-------------------------------------------------------" << endl;

		dir = fopen(fileName, "r");

		if (dir != NULL) {	//makes sure program doesn't run if file not found
			while (flag == true) {
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> ";
				cin >> input;
				if (strCmp("!", input) == 0) {	//checking for the exit character to exit program
					flag = false;
				}
				else {
					toLowerCaseAndCopy(input, input);
					while (fscanf(dir, "%[^\t]\t%s\t%s\t%s\n", fname, area, prefix, number) != -1) {
						strCpy(tname, fname);	//saving capitalized name for display
						toLowerCaseAndCopy(fname, fname);
						if (strStr(fname, input) != 0) {
							cout << tname << ": (" << area << ") " << prefix << "-" << number << endl;
						}
					}
					rewind(dir);	//rewinds to beginning of file for the new name search
				}
			}
			fclose(dir);
		}
		else {
			cout << fileName << " file not found!" << endl;
		}
		cout << "Thank you for using " << programTitle << " directory." << endl;
	}
}
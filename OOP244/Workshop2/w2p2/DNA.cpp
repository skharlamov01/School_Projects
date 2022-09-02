/* Workshop 2 Part 2
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 28/01/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "cStrTools.h"
#include "DNA.h"
using namespace std;

namespace sdds
{
	FILE* fptr = NULL;
	matchDNA* matches = nullptr;	//dynamic array of matched dna 
	int allocsize = 5;	//# of indexes to be allocated when needed
	int arrsize = 5;	//how many indexes in the matches array
	int matchcount = 0;	//how many matching dna were found

	bool beginSearch(const char* filename)
	{
		fptr = fopen(filename, "r");
		if (fptr != nullptr) {
			matches = new matchDNA[arrsize];
			cout << "DNA search program" << endl;
			return true;
		}
		else {
			return false;
		}
	}
	bool read(const char* subDNA)
	{
		int tmpnum = 0;
		char tmpstr[1001];
		while (fscanf(fptr, "%d,%s", &tmpnum, tmpstr) == 2){	//run loop until end of file is reached
			if (matchcount >= arrsize) {	//checks if the array needs resizing
				matchDNA* tmparr = new matchDNA[arrsize + allocsize];
				for (int i = 0; i < arrsize; i++) {
					tmparr[i] = matches[i];
				}
				delete[] matches;
				arrsize += allocsize;
				matches = tmparr;
			}
			if (strStr(tmpstr, subDNA) != nullptr) {	//looks for a dna match, if found scans it into dynamic array
				matches[matchcount].code = new char[strLen(tmpstr) + 1];
				strCpy(matches[matchcount].code, tmpstr);
				matches[matchcount].num = tmpnum;
				matchcount++;
			}
		}
		if (matchcount > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//swaps places of two instances of the matchDNA struct
	void swap(struct matchDNA* a, struct matchDNA* b) {
		struct matchDNA tmp = *a;
		*a = *b;
		*b = tmp;
	}
	//uses selection sort to sort the dna results by num in ascending order
	void sort()
	{
		for (int i = 0; i < matchcount - 1; i++) {
			struct matchDNA tmp = matches[i];
			for (int j = i + 1; j < matchcount; j++) {
				if (matches[j].num < tmp.num) {
					tmp = matches[j];
					swap(&matches[j], &matches[i]);
				}
			}
		}
	}
	void displayMatches()
	{
		int j = 1;
		cout << matchcount << " matches found:" << endl;
		for (int i = 0; i < matchcount; i++, j++) {
			cout << j << ") " << matches[i].num << ":" << endl;
			cout << matches[i].code << endl;
			cout << "======================================================================" << endl;
		}
	}
	void deallocate()
	{
		for (int i = 0; i < matchcount; i++) {
			delete[] matches[i].code;
			matches[i].code = nullptr;
		}
		delete[] matches;
		matches = nullptr;
		rewind(fptr);
		matchcount = 0;
	}
	void endSearch()
	{
		fclose(fptr);
		cout << "DNA Search Program Closed." << endl;
	}
}
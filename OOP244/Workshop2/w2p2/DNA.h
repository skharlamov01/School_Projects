/* Workshop 2 Part 2
Name: Sasha Kharlamov
Email: skharlamov@myseneca.ca
Seneca ID: 150707214
Date: 28/01/2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_DNA_H
#define SDDS_DNA_H

namespace sdds
{
	struct matchDNA {
		char* code;
		int num;
	};
	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	//swaps places of two instances of the matchDNA struct
	void swap(struct matchDNA* a, struct matchDNA* b);
	//uses selection sort to sort the dna results by num in ascending order
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
}
#endif // !SDDS_DNA_H
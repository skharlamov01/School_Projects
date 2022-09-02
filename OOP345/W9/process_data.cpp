/*Workshop 9
Author : Sasha Kharlamov
Author ID : 150707214
Author Email : skharlamov@myseneca.ca
Date : 2022/07/31
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- - */
// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

#include "process_data.h"

using namespace std::placeholders;
namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
		std::ifstream file(filename, std::ios::binary);
		file.read((char*)&total_items, sizeof(total_items));
		
		data = new int[total_items];	//allocating mem in data
		for (auto i = 0; i < total_items; i++) {	//loop to copy into allocated mem
			int num{};
			file.read((char*)&num, sizeof(num));
			data[i] = num;
		}


		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.
	int ProcessData::operator()(std::string filename, double& avgVal, double& varVal) {
		std::vector<std::thread> threads;
		for (int i = 0; i < num_threads; i++) {	//computing the average block
			auto compAvg = std::bind(computeAvgFactor, _1, _2, total_items, _3);
			std::thread th(compAvg, &data[p_indices[i]], total_items / num_threads, std::ref(averages[i]));
			threads.push_back(std::move(th));
		}
		for (auto& thread : threads) {
			thread.join();
		}
		for (int i = 0; i < num_threads; i++) {	//loop to combine all averages
			avgVal += averages[i];
		}
		threads.clear();	//cleaning threads vector to be reused
		
		for (int i = 0; i < num_threads; i++) {	//computing the variance block
			auto compVar = std::bind(computeVarFactor, _1, _2, total_items, avgVal, _3);
			std::thread th(compVar, &data[p_indices[i]], (total_items / num_threads), std::ref(variances[i]));
			threads.push_back(std::move(th));
		}
		for (auto& thread : threads) {
			thread.join();
		}
		for (int i = 0; i < num_threads; i++) {	//loop to combine all variances
			varVal += variances[i];
		}
		//writing to output file
		std::ofstream file;
		file.open(filename, std::ios::binary);
		file.write((const char*)&total_items, sizeof(total_items));
		for (auto i = 0; i < total_items; i++) {
			file.write((const char*)&data[i], sizeof(data[i]));
		}
		return 0;
	}
}
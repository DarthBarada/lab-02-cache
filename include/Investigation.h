#pragma once
#include "Experiment.h"
#include <random>
#include <string>
#include <stdexcept>

// Class investigaion
class Investigation
	{
	public:
		std::string travel_variant; // Type of moving
		std::vector <experiment> exper; // Vector of experiments

		Investigation();
		Investigation(const std::string s);
		~Investigation();

		void FrontPassExperiment();
		void BackPassExperiment();
		void RandomPassExperiment();
		void print();

	};

Investigation::Investigation()
	{
		travel_variant = "random pass";
		for (size_t i = 0; i < buffer_sizes.size(); i++)
			{
				exper.push_back(*new experiment(int(buffer_sizes.at(i))));
			}
	}

Investigation::~Investigation()
	{
		travel_variant.clear();
		
		for (auto i = exper.begin(); i != exper.end(); i++)
			{
				delete[] i->array;
			}
	}

Investigation::Investigation(const std::string s)
	{
		travel_variant = s;
		for (size_t i = 0; i < buffer_sizes.size(); i++)
			{
				exper.push_back(*new experiment(int(buffer_sizes.at(i))));
			}
		if (s.compare("front pass") == 0)
			{
				FrontPassExperiment();
			}
		if (s.compare("reverse pass") == 0)
			{
				BackPassExperiment();
			}
		if (s.compare("random pass") == 0)
			{
				RandomPassExperiment();
			}
		print();
	}

void Investigation::FrontPassExperiment()
	{
		for (auto index = exper.begin(); index != exper.end(); index++)
			{
				//
				//----           Warming
				//
				for (unsigned int i = 0; i < index->count_of_elements; i++)
					{
						index->array[i] = rand() % 1000000;
					}
				//
				//----      End of warming
				//

				// Begin of experiment

				auto begin = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < 1000; i++)// <- Is this a pass?
					{
						for (unsigned int j = 0; j < index->count_of_elements; j++) // <- Is this a pass?
							{
								index->array[j] = rand() % 1000;
							}
					}
				auto end = std::chrono::high_resolution_clock::now();
				index->work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

				// End of experiment
			}
	}

void Investigation::BackPassExperiment()
	{
		for (auto index = exper.begin(); index != exper.end(); index++)
			{
				//
				//----           Warming
				//
				for (unsigned int i = 0; i < index->count_of_elements; i++)
					{
						index->array[i] = rand() % 1000000;
					}
				//
				//----      End of warming
				//

				// Begin of experiment

				auto begin = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < 1000; i++)// <- Is this a pass?
					{
						for (unsigned int j = index->count_of_elements - 1; j >= 0; j--) // <- Is this a pass?
							{
								index->array[j] = rand() % 1000;
							}
					}
				auto end = std::chrono::high_resolution_clock::now();
				index->work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

				// End of experiment
			}
	}

void Investigation::RandomPassExperiment()
	{
		for (auto index = exper.begin(); index != exper.end(); index++)
			{
				//
				//----           Warming
				//
				for (unsigned int i = 0; i < index->count_of_elements; i++)
					{
						index->array[i] = rand() % 1000000;
					}
				//
				//----      End of warming
				//

				// Begin of experiment

				std::random_device rd;		// генерирует равномерно распределенные целые случайные числа
				std::mt19937 gen(rd());		// двигатель рандомных чисел
				std::uniform_int_distribution<> dis(0, index->count_of_elements);
				
				auto begin = std::chrono::high_resolution_clock::now();
				for (int i = 0; i < 1000; i++)// <- Is this a pass?
					{
						for (unsigned int j = 0; j < index->count_of_elements; j++) // <- Is this a pass?
							{
								index->array[dis(gen)] = rand() % 1000;
							}
					}
				auto end = std::chrono::high_resolution_clock::now();
				index->work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

				// End of experiment
			}
	}

void Investigation::print()
	{
		std::cout << "investigation:\n";
		std::cout << "\ttravel_order:" << travel_variant << "\n";
		std::cout << "\texperiments:\n";
		for (size_t i = 0; i < exper.size(); i++)
			{
				std::cout << "\t - experiment:\n"
					<< "\t    number: " << int(i + 1) << "\n"
					<< "\t    input_data:\n"
					<< "\t      buffer_size: \"" << exper.at(i).buffer_size << " mb\"\n"
					<< "\t    results:\n"
					<< "\t      duration: \"" << exper.at(i).work_time.count() << " ms\"\n";
			}
	}

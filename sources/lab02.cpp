// Copyright 2019 Dmitry Mitrofanov <DarthBarada@gmail.com>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <stdexcept>

const std::vector <unsigned int> buffer_sizes{ 1,2,4,8,12 }; // Vector of avaliable sizes

// Class experiment
class experiment
{
public:
	unsigned int count_of_elements = 0;     // Size of array
	int* array;                           // Pointer on array
	unsigned int buffer_size = 0;           // Size of memory for array
	std::chrono::milliseconds work_time;   // Time for experiment

	  // Constructor with data/buffer size (mb)
	experiment(unsigned int mbytes)
		{
			for (size_t i = 0; i < buffer_sizes.size(); i++)
				{
					if (buffer_sizes.at(i) == mbytes)
						{
							buffer_size = mbytes;
							break;
						}
				}
			if (buffer_size == 0)
				{
					throw std::runtime_error("Wrong value of cache size mb!"); // if size of array belongs to buffer_sizes ,then programm is throwing an error
				}
			count_of_elements = int(buffer_size * 512 * 512); // Translate 1 mbytes-> 1024 kbytes -> 1024 * 1024 bytes and devide on 4 bytes - size of 1 int object
			array = new int[count_of_elements]; // Create new array with given size
		}
	virtual ~experiment()
		{}
};

// Class investigaion
class Investigation
	{
	public:
		std::string travel_variant; // Type of moving
		std::vector <experiment> exper; // Vector of experiments

		Investigation(const std::string s)
			{
				travel_variant = s;
				for (size_t i = 0; i<buffer_sizes.size(); i++)
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
						srand(time(nullptr));
						int a = rand() % 2;
						if (a == 1)
							{
								FrontPassExperiment();
							}
						else
							{
								BackPassExperiment();
							}
					}
				print();
			}

		void Experiment(experiment& s, bool type) // true -> frontpass;flase - invertedpass
			{
				//
				//----           Warming
				//
				for (unsigned int i = 0; i < s.count_of_elements; i++)
					{
						s.array[i] = rand() % 1000000;
					}
				//
				//----      End of warming
				//

				// Begin of experiment
				
				if (type)
					{
						auto begin = std::chrono::high_resolution_clock::now();
						for (int i = 0; i < 1000; i++)// <- Is this a pass?
							{
								for (unsigned int j = 0; j < s.count_of_elements; j++) // <- Is this a pass?
									{
										s.array[j] = rand() % 1000;
									}
							}
						auto end = std::chrono::high_resolution_clock::now();
						s.work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
					}
				else
					{
						auto begin = std::chrono::high_resolution_clock::now();
						for (int i = 0; i < 1000; i++)// <- Is this a pass?
							{
								for (unsigned int j = s.count_of_elements; j > 0; j--) // <- Is this a pass?
									{
										s.array[j] = rand() % 1000;
									}
							}
						auto end = std::chrono::high_resolution_clock::now();
						s.work_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
					}
				// End of experiment
				

				
			}
		void FrontPassExperiment()
			{
				for (size_t i = 0; i < exper.size(); i++)
					{
						Experiment(exper.at(i), true);
					}
			}
		void BackPassExperiment()
			{
				for (size_t i = 0; i < exper.size(); i++)
					{
						Experiment(exper.at(i), false);
					}
			}
		void print()
			{
				std::cout << "investigation:\n";
				std::cout << "\ttravel_order:" << travel_variant << "\n";
					std::cout << "\texperiments:\n";
				for (size_t i = 0; i < exper.size(); i++)
					{
						std::cout << "\t - experiment:\n"
							<< "\t    number: " << int(i+1)<<"\n"
							<< "\t    input_data:\n"
							<< "\t      buffer_size: \"" << exper.at(i).buffer_size << " mb\"\n"
							<< "\t    results:\n"
							<< "\t      duration: \"" << exper.at(i).work_time.count() << " ms\"\n";
					}
			}
		virtual ~Investigation(){}
	};

int main()
	{
		Investigation front("front pass");
		Investigation back("reverse pass");
		Investigation random("random pass");

		return 0;
	}
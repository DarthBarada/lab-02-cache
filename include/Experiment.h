#pragma once
#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>

const std::vector <unsigned int> buffer_sizes{ 1,2,4,8,12 }; // Vector of avaliable sizes

// Class experiment
class experiment
	{
		public:
			unsigned int count_of_elements = 0;     // Size of array
			int* array;             // Pointer on array
			unsigned int buffer_size = 0;           // Size of memory for array
			std::chrono::milliseconds work_time;    // Time for experiment

			experiment()
				{
					std::srand(time(NULL));
					buffer_size = buffer_sizes.at(rand() % 5);
					count_of_elements = int(buffer_size * 512 * 512); // Translate 1 mbytes-> 1024 kbytes -> 1024 * 1024 bytes and devide on 4 bytes - size of 1 int object
					array = new int[count_of_elements]; // Create new array with given size
				}

			  // Constructor with data/buffer size (mb)
			experiment(unsigned int mbytes)
				{
					if (std::find(buffer_sizes.begin(), buffer_sizes.end(), mbytes) == buffer_sizes.end())
						{
							throw std::runtime_error("Wrong value of cache size mb!"); // if size of array belongs to buffer_sizes ,then programm is throwing an error
						}
					count_of_elements = int(mbytes * 512 * 512); // Translate 1 mbytes-> 1024 kbytes -> 1024 * 1024 bytes and devide on 4 bytes - size of 1 int object
					array = new int[count_of_elements]; // Create new array with given size
				}
			virtual ~experiment() = default;

	};

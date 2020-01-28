// EzRandomRunner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

#include "../EzRandom/EzRandom.h"

int main()
{
    EzRandomInt<short> ezi(0, std::numeric_limits<short>::max(), true, true);

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ezi.GetNext() << std::endl;
	}

	EzRandomReal<double> ezf(0, 1, true, true);

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ezf.GetNext() << std::endl;
	}
}

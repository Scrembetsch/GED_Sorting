#include <iostream>

#include "ArgumentParser.h"
#include "Timing.h"
#include "Random.h"
#include "QuickSort.h"

int main(int argc, char** argv)
{
	ArgumentParser arg(argc, argv);
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = Random(0, 30);
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	QuickSort::Sort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

}
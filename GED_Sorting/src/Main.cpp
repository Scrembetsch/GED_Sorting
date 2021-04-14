#include <iostream>
#include <string>

#include "ArgumentParser.h"
#include "Timing.h"
#include "Random.h"
#include "ComplexObject.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "BucketSort.h"

const size_t CacheArraySize = 1000;
const size_t RamArraySize = 1000000;

int* IntCache;
int* IntRam;
ComplexObject* ObjectCache;
ComplexObject* ObjectRam;

template<typename T>
void CopyArray(T* original, T* destination, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		destination[i] = original[i];
	}
}

void PrintArray(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ";";
	}
	std::cout << std::endl;
}

void PrintArray(ComplexObject* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i].ToString() << ";";
	}
	std::cout << std::endl;
}

void Variant1()
{
	std::string variant("Variant 1 - ");
	std::cout << variant << std::endl;

	int* bubbleCopy = new int[CacheArraySize];
	CopyArray(IntCache, bubbleCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Bubble");
	BubbleSort::Sort(bubbleCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	int* insertCopy = new int[CacheArraySize];
	CopyArray(IntCache, insertCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Insertion");
	InsertionSort::Sort(insertCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	int* quickCopy = new int[CacheArraySize];
	CopyArray(IntCache, quickCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Quick");
	QuickSort::Sort(quickCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	int* bucketCopy = new int[CacheArraySize];
	CopyArray(IntCache, bucketCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Bucket");
	BucketSort::Sort(bucketCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant2()
{
	std::string variant("Variant 2 - ");
	std::cout << variant << std::endl;

	int* bubbleCopy = new int[RamArraySize];
	CopyArray(IntRam, bubbleCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Bubble");
	BubbleSort::Sort(bubbleCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	int* insertCopy = new int[RamArraySize];
	CopyArray(IntRam, insertCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Insertion");
	InsertionSort::Sort(insertCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	int* quickCopy = new int[RamArraySize];
	CopyArray(IntRam, quickCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Quick");
	QuickSort::Sort(quickCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	int* bucketCopy = new int[RamArraySize];
	CopyArray(IntRam, bucketCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Bucket");
	BucketSort::Sort(bucketCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant3()
{
	std::string variant("Variant 3 - ");
	std::cout << variant << std::endl;

	ComplexObject* bubbleCopy = new ComplexObject[CacheArraySize];
	CopyArray(ObjectCache, bubbleCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Bubble");
	BubbleSort::Sort(bubbleCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	ComplexObject* insertCopy = new ComplexObject[CacheArraySize];
	CopyArray(ObjectCache, insertCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Insertion");
	InsertionSort::Sort(insertCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	ComplexObject* quickCopy = new ComplexObject[CacheArraySize];
	CopyArray(ObjectCache, quickCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Quick");
	QuickSort::Sort(quickCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	PrintArray(quickCopy, CacheArraySize);
	delete[] quickCopy;

	ComplexObject* bucketCopy = new ComplexObject[CacheArraySize];
	CopyArray(ObjectCache, bucketCopy, CacheArraySize);
	Timing::getInstance()->startRecord(variant + "Bucket");
	BucketSort::Sort(bucketCopy, CacheArraySize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant4()
{
	std::string variant("Variant 4 - ");
	std::cout << variant << std::endl;
}

void Variant5()
{
	std::string variant("Variant 5 - ");
	std::cout << variant << std::endl;

	ComplexObject* bubbleCopy = new ComplexObject[RamArraySize];
	CopyArray(ObjectRam, bubbleCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Bubble");
	BubbleSort::Sort(bubbleCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	ComplexObject* insertCopy = new ComplexObject[RamArraySize];
	CopyArray(ObjectRam, insertCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Insertion");
	InsertionSort::Sort(insertCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	ComplexObject* quickCopy = new ComplexObject[RamArraySize];
	CopyArray(ObjectRam, quickCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Quick");
	QuickSort::Sort(quickCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	ComplexObject* bucketCopy = new ComplexObject[RamArraySize];
	CopyArray(ObjectRam, bucketCopy, RamArraySize);
	Timing::getInstance()->startRecord(variant + "Bucket");
	BucketSort::Sort(bucketCopy, RamArraySize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant6()
{
	std::string variant("Variant 6 - ");
	std::cout << variant << std::endl;
}

void Variant7()
{
	std::string variant("Variant 7 - ");
	std::cout << variant << std::endl;
}

void Variant8()
{
	std::string variant("Variant 8 - ");
	std::cout << variant << std::endl;
}

int main(int argc, char** argv)
{
	ArgumentParser arg(argc, argv);

	IntCache = new int[CacheArraySize];
	IntRam = new int[RamArraySize];
	ObjectCache = new ComplexObject[CacheArraySize];
	ObjectRam = new ComplexObject[RamArraySize];

	for (size_t i = 0; i < CacheArraySize; i++)
	{
		IntCache[i] = Random(0, INT32_MAX);
	}
	for (size_t i = 0; i < RamArraySize; i++)
	{
		IntRam[i] = Random(0, INT32_MAX);
	}
	for (size_t i = 0; i < CacheArraySize; i++)
	{
		ObjectCache[i] = ComplexObject();
	}
	for (size_t i = 0; i < RamArraySize; i++)
	{
		ObjectRam[i] = ComplexObject();
	}
	PrintArray(ObjectCache, CacheArraySize);
	Variant1();
	Variant2();
	Variant3();
	Variant4();
	Variant5();
	Variant6();
	Variant7();
	Variant8();

	Timing::getInstance()->print();
	Timing::getInstance()->clear();

	delete[] IntCache;
	delete[] IntRam;
	delete[] ObjectCache;
	delete[] ObjectRam;
}
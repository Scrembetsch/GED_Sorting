#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string>

#include "ArgumentParser.h"
#include "Timing.h"
#include "Random.h"
#include "ComplexObject.h"
#include "Sort.h"

// Number of elements if the array should fit into the cache
const size_t IntCacheSize = 100000;
const size_t IntRamSize = 10000000;
// Number of elements if the array should not fit into the cache
const size_t ObjectCacheSize = 100000;
const size_t ObjectRamSize = 10000000;

const std::string Bubble = "Bubble";
const std::string Insertion = "Insertion";
const std::string Quick = "Quick";
const std::string Bucket = "Bucket";
const std::string Std = "Std";

int* IntCache;
int* IntRam;
ComplexObject* ObjectCache;
ComplexObject* ObjectRam;

int** IntPtrCache;
int** IntPtrRam;
ComplexObject** ObjectPtrCache;
ComplexObject** ObjectPtrRam;

template<typename T>
bool Equals(const T& a, const T& b)
{
	return a == b;
}

template<typename T>
bool EqualsPtr(const T& a, const T& b)
{
	return *a == *b;
}

template<typename T>
size_t GetInt(const T& a)
{
	return size_t(a);
}

template<typename T>
size_t GetIntPtr(const T& a)
{
	return size_t(*a);
}

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

void PrintArray(int** arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << *arr[i] << ";";
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

void PrintArray(ComplexObject** arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << (*arr[i]).ToString() << ";";
	}
	std::cout << std::endl;
}

template<typename T, typename C>
void VariantTest(const std::string& variant, T* originalArray, size_t size, C compare, size_t(*getIntFunction)(const T&))
{
	if (size < 500000)
	{
		// Bubble Sort
		T* bubbleCopy = new T[size];
		CopyArray(originalArray, bubbleCopy, size);
		Timing::getInstance()->startRecord(variant + Bubble, true);
		BubbleSort::Sort(bubbleCopy, size, compare);
		Timing::getInstance()->stopRecord(variant + Bubble);
		delete[] bubbleCopy;

		// Insertion Sort
		T* insertCopy = new T[size];
		CopyArray(originalArray, insertCopy, size);
		Timing::getInstance()->startRecord(variant + Insertion, true);
		InsertionSort::Sort(insertCopy, size, compare);
		Timing::getInstance()->stopRecord(variant + Insertion);
		delete[] insertCopy;
	}
	else
	{
		Timing::getInstance()->startRecord(variant + Bubble, true);
		Timing::getInstance()->stopRecord(variant + Bubble);
		Timing::getInstance()->startRecord(variant + Insertion, true);
		Timing::getInstance()->stopRecord(variant + Insertion);

		std::cout << "Bubble & Insertion sort were skipped!" << std::endl;
	}

	// Quick Sort
	T* quickCopy = new T[size];
	CopyArray(originalArray, quickCopy, size);
	Timing::getInstance()->startRecord(variant + Quick, true);
	QuickSort::Sort(quickCopy, size, compare);
	Timing::getInstance()->stopRecord(variant + Quick);
	delete[] quickCopy;

	// Bucket Sort
	T* bucketCopy = new T[size];
	CopyArray(originalArray, bucketCopy, size);
	Timing::getInstance()->startRecord(variant + Bucket, true);
	BucketSort::Sort(bucketCopy, size, compare, getIntFunction);
	Timing::getInstance()->stopRecord(variant + Bucket);
	delete[] bucketCopy;

	// Std::sort
	T* stdCopy = new T[size];
	CopyArray(originalArray, stdCopy, size);
	Timing::getInstance()->startRecord(variant + Std, true);
	std::sort(stdCopy, stdCopy + size, compare);
	Timing::getInstance()->stopRecord(variant + Std);
	delete[] stdCopy;
}

// Setup arrays that contain simple integers
void SetupIntArrays()
{
	IntCache = new int[IntCacheSize];
	IntRam = new int[IntRamSize];

	for (size_t i = 0; i < IntCacheSize; i++)
	{
		IntCache[i] = Random(0, INT32_MAX);
	}
	for (size_t i = 0; i < IntRamSize; i++)
	{
		IntRam[i] = Random(0, INT32_MAX);
	}
}

// Setup arrays that contain more complex objects (instead of simple integers)
void SetupObjectArrays()
{
	ObjectCache = new ComplexObject[ObjectCacheSize];
	ObjectRam = new ComplexObject[ObjectRamSize];

	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		ObjectCache[i] = ComplexObject();
	}
	for (size_t i = 0; i < ObjectRamSize; i++)
	{
		ObjectRam[i] = ComplexObject();
	}
}

// Setup arrays that contain pointers to simple integers
void SetupIntPtrArrays()
{
	IntPtrCache = new int*[IntCacheSize];
	IntPtrRam = new int*[IntRamSize];

	for (size_t i = 0; i < IntCacheSize; i++)
	{
		IntPtrCache[i] = new int(IntCache[i]);
	}
	for (size_t i = 0; i < IntRamSize; i++)
	{
		IntPtrRam[i] = new int(IntRam[i]);
	}
}

// Setup arrays that contain pointers to more complex objects (instead of simple integers)
void SetupObjectPtrArrays()
{
	ObjectPtrCache = new ComplexObject*[ObjectCacheSize];
	ObjectPtrRam = new ComplexObject*[ObjectRamSize];

	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		ObjectPtrCache[i] = new ComplexObject(ObjectCache[i]);
	}
	for (size_t i = 0; i < ObjectRamSize; i++)
	{
		ObjectPtrRam[i] = new ComplexObject(ObjectRam[i]);
	}
}

void SetupArrays()
{
	SetupIntArrays();
	SetupObjectArrays();
	SetupIntPtrArrays();
	SetupObjectPtrArrays();
}

// Delete all previously allocated memory
void Cleanup()
{
	Timing::getInstance()->clear();

	delete[] IntCache;
	delete[] IntRam;
	delete[] ObjectCache;
	delete[] ObjectRam;

	for (size_t i = 0; i < IntCacheSize; i++)
	{
		delete IntPtrCache[i];
	}
	for (size_t i = 0; i < IntRamSize; i++)
	{
		delete IntPtrRam[i];
	}
	delete[] IntPtrCache;
	delete[] IntPtrRam;

	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		delete ObjectPtrCache[i];
	}
	for (size_t i = 0; i < ObjectRamSize; i++)
	{
		delete ObjectPtrRam[i];
	}
	delete[] ObjectPtrCache;
	delete[] ObjectPtrRam;
}

// Function for verifying if all algorithms sorted the given data correctly
template<typename T, typename C>
void VerifySort(const std::string& verifyName, T* originalArray, size_t size, C compare, bool(*compareFunction)(const T&, const T&), size_t(*getIntFunction)(const T&))
{
	T* stdCopy = new T[size];
	CopyArray(originalArray, stdCopy, size);
	std::sort(stdCopy, stdCopy + size, compare);

	std::cout << "Verifying " << verifyName << " Bubble" << std::endl;
	T* bubbleCopy = new T[size];
	CopyArray(originalArray, bubbleCopy, size);
	BubbleSort::Sort(bubbleCopy, size, compare);
	for (size_t i = 0; i < size; i++)
	{
		assert(compareFunction(stdCopy[i], bubbleCopy[i]));
	}
	delete[] bubbleCopy;

	std::cout << "Verifying " << verifyName << " Insert" << std::endl;
	T* insertCopy = new T[size];
	CopyArray(originalArray, insertCopy, size);
	InsertionSort::Sort(insertCopy, size, compare);
	for (size_t i = 0; i < size; i++)
	{
		assert(compareFunction(stdCopy[i], insertCopy[i]));
	}
	delete[] insertCopy;

	std::cout << "Verifying " << verifyName << " Quick" << std::endl;
	T* quickCopy = new T[size];
	CopyArray(originalArray, quickCopy, size);
	QuickSort::Sort(quickCopy, size, compare);
	for (size_t i = 0; i < size; i++)
	{
		assert(compareFunction(stdCopy[i], quickCopy[i]));
	}
	delete[] quickCopy;

	std::cout << "Verifying " << verifyName << " Bucket" << std::endl;
	T* bucketCopy = new T[size];
	CopyArray(originalArray, bucketCopy, size);
	BucketSort::Sort(bucketCopy, size, compare, getIntFunction);
	for (size_t i = 0; i < size; i++)
	{
		assert(compareFunction(stdCopy[i], bucketCopy[i]));
	}
	delete[] bucketCopy;

	delete[] stdCopy;
}

void VerifySorting()
{
	VerifySort("Int", IntCache, IntCacheSize, Sort::Lesser<>{}, &Equals, &GetInt);
	VerifySort("IntPtr", IntPtrCache, IntCacheSize, Sort::LesserPtr<>{}, &EqualsPtr, &GetIntPtr);
	VerifySort("Object", ObjectCache, ObjectCacheSize, Sort::Lesser<>{}, &Equals, &GetInt);
	VerifySort("ObjectPtr", ObjectPtrCache, ObjectCacheSize, Sort::LesserPtr<>{}, &EqualsPtr, &GetIntPtr);
}

std::string ParseTime(double time)
{
	int ms = int(time);
	int minutes = (int)(ms / 1000 / 60);
	int seconds = (int)((ms % (1000 * 60)) / 1000);
	int milliseconds = (int)(ms % 1000);

	if (seconds == 60)
	{
		minutes++;
		seconds = 0;
	}

	std::ostringstream stringStream;
	if (minutes > 0)
	{
		stringStream << minutes << "m ";
	}
	if (seconds > 0)
	{
		stringStream << seconds << "s ";
	}
	if (milliseconds > 0)
	{
		stringStream << milliseconds << "ms ";
	}
	return stringStream.str();
}

int main(int argc, char** argv)
{
	ArgumentParser arg(argc, argv);
	std::map<std::string, double> times;

	if (arg.CheckIfExists("-v", "--verify"))
	{
		SetupArrays();
		VerifySorting();
		Cleanup();
	}
	else
	{
		int loops = arg.GetInt("-l", "--loops", 1);		// Number of iterations for more accurate results
		for (int i = 0; i < loops; i++)
		{
			SetupArrays();

			// Test all 8 variants - see documentation for more information
			VariantTest("Variant 1 - ", IntCache, IntCacheSize, Sort::Lesser<>{}, & GetInt);
			VariantTest("Variant 2 - ", IntRam, IntRamSize, Sort::Lesser<>{}, & GetInt);
			VariantTest("Variant 3 - ", ObjectCache, ObjectCacheSize, Sort::Lesser<>{}, & GetInt);
			VariantTest("Variant 4 - ", IntPtrCache, IntCacheSize, Sort::LesserPtr<>{}, & GetIntPtr);
			VariantTest("Variant 5 - ", ObjectRam, ObjectRamSize, Sort::Lesser<>{}, & GetInt);
			VariantTest("Variant 6 - ", IntPtrRam, IntRamSize, Sort::LesserPtr<>{}, & GetIntPtr);
			VariantTest("Variant 7 - ", ObjectPtrCache, ObjectCacheSize, Sort::LesserPtr<>{}, & GetIntPtr);
			VariantTest("Variant 8 - ", ObjectPtrRam, ObjectRamSize, Sort::LesserPtr<>{}, & GetIntPtr);

			for (int j = 1; j <= 8; j++)
			{
				std::string variant = "Variant " + std::to_string(j) + " - ";
				if (times.find(variant + Bubble) == times.end())
				{
					times.insert(std::make_pair(variant + Bubble, Timing::getInstance()->getRecord(variant + Bubble)));
					times.insert(std::make_pair(variant + Insertion, Timing::getInstance()->getRecord(variant + Insertion)));
					times.insert(std::make_pair(variant + Quick, Timing::getInstance()->getRecord(variant + Quick)));
					times.insert(std::make_pair(variant + Bucket, Timing::getInstance()->getRecord(variant + Bucket)));
					times.insert(std::make_pair(variant + Std, Timing::getInstance()->getRecord(variant + Std)));
				}
				else
				{
					times.at(variant + Bubble) += Timing::getInstance()->getRecord(variant + Bubble);
					times.at(variant + Insertion) += Timing::getInstance()->getRecord(variant + Insertion);
					times.at(variant + Quick) += Timing::getInstance()->getRecord(variant + Quick);
					times.at(variant + Bucket) += Timing::getInstance()->getRecord(variant + Bucket);
					times.at(variant + Std) += Timing::getInstance()->getRecord(variant + Std);
				}
			}

			Cleanup();
		}

		// Print results
		for (int j = 1; j <= 8; j++)
		{
			std::string variant = "Variant " + std::to_string(j) + " - ";
			std::cout << "+ Variant " + std::to_string(j) << std::endl;
			std::cout << "- " << Bubble << ": " << ParseTime(times.at(variant + Bubble) / loops) << std::endl;
			std::cout << "- " << Insertion << ": " << ParseTime(times.at(variant + Insertion) / loops) << std::endl;
			std::cout << "- " << Quick << ": " << ParseTime(times.at(variant + Quick) / loops) << std::endl;
			std::cout << "- " << Bucket << ": " << ParseTime(times.at(variant + Bucket) / loops) << std::endl;
			std::cout << "- " << Std << ": " << ParseTime(times.at(variant + Std) / loops) << std::endl;
		}

	}
}
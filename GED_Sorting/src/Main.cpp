#include <assert.h>
#include <iostream>
#include <string>

#include "ArgumentParser.h"
#include "Timing.h"
#include "Random.h"
#include "ComplexObject.h"
#include "Sort.h"

const size_t IntCacheSize = 100000;
const size_t IntRamSize = 10000000;
const size_t ObjectCacheSize = 100000;
const size_t ObjectRamSize = 10000000;

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
	T* bubbleCopy = new T[size];
	CopyArray(originalArray, bubbleCopy, size);
	Timing::getInstance()->startRecord(variant + "Bubble", true);
	BubbleSort::Sort(bubbleCopy, size, compare);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	T* insertCopy = new T[size];
	CopyArray(originalArray, insertCopy, size);
	Timing::getInstance()->startRecord(variant + "Insertion", true);
	InsertionSort::Sort(insertCopy, size, compare);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	T* quickCopy = new T[size];
	CopyArray(originalArray, quickCopy, size);
	Timing::getInstance()->startRecord(variant + "Quick", true);
	QuickSort::Sort(quickCopy, size, compare);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	T* bucketCopy = new T[size];
	CopyArray(originalArray, bucketCopy, size);
	Timing::getInstance()->startRecord(variant + "Bucket", true);
	BucketSort::Sort(bucketCopy, size, compare, getIntFunction);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

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

template<typename T, typename C>
void VerifySort(const std::string& verifyName, T* originalArray, size_t size, C compare, bool(*compareFunction)(const T&, const T&), size_t(*getIntFunction)(const T&))
{
	std::cout << "Original: ";
	PrintArray(originalArray, size);
	T* stdCopy = new T[size];
	CopyArray(originalArray, stdCopy, size);
	std::sort(stdCopy, stdCopy + size, compare);
	PrintArray(stdCopy, size);

	std::cout << "Verifying " << verifyName << " Bubble" << std::endl;
	T* bubbleCopy = new T[size];
	CopyArray(originalArray, bubbleCopy, size);
	BubbleSort::Sort(bubbleCopy, size, compare);
	PrintArray(bubbleCopy, size);
	for (size_t i = 0; i < size; i++)
	{
		assert(compareFunction(stdCopy[i], bubbleCopy[i]));
	}
	delete[] bubbleCopy;

	std::cout << "Verifying " << verifyName << " Insert" << std::endl;
	T* insertCopy = new T[size];
	CopyArray(originalArray, insertCopy, size);
	InsertionSort::Sort(insertCopy, size, compare);
	PrintArray(insertCopy, size);
	for (size_t i = 0; i < size; i++)
	{
		assert(compareFunction(stdCopy[i], insertCopy[i]));
	}
	delete[] insertCopy;

	std::cout << "Verifying " << verifyName << " Quick" << std::endl;
	T* quickCopy = new T[size];
	CopyArray(originalArray, quickCopy, size);
	QuickSort::Sort(quickCopy, size, compare);
	PrintArray(quickCopy, size);
	for (size_t i = 0; i < size; i++)
	{
		assert(compareFunction(stdCopy[i], quickCopy[i]));
	}
	delete[] quickCopy;

	std::cout << "Verifying " << verifyName << " Bucket" << std::endl;
	T* bucketCopy = new T[size];
	CopyArray(originalArray, bucketCopy, size);
	BucketSort::Sort(bucketCopy, size, compare, getIntFunction);
	PrintArray(bucketCopy, size);
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

int main(int argc, char** argv)
{
	ArgumentParser arg(argc, argv);

	SetupArrays();

	if (arg.CheckIfExists("", "--verify"))
	{
		VerifySorting();
	}
	else
	{
		VariantTest("Variant 1 - ", IntCache, IntCacheSize, Sort::Lesser<>{}, &GetInt);
		VariantTest("Variant 2 - ", IntRam, IntRamSize, Sort::Lesser<>{}, &GetInt);
		VariantTest("Variant 3 - ", ObjectCache, ObjectCacheSize, Sort::Lesser<>{}, &GetInt);
		VariantTest("Variant 4 - ", IntPtrCache, IntCacheSize, Sort::LesserPtr<>{}, &GetIntPtr);
		VariantTest("Variant 5 - ", ObjectRam, ObjectRamSize, Sort::Lesser<>{}, &GetInt);
		VariantTest("Variant 6 - ", IntPtrRam, IntRamSize, Sort::LesserPtr<>{}, &GetIntPtr);
		VariantTest("Variant 7 - ", ObjectPtrCache, ObjectCacheSize, Sort::LesserPtr<>{}, &GetIntPtr);
		VariantTest("Variant 8 - ", ObjectPtrRam, ObjectRamSize, Sort::LesserPtr<>{}, &GetIntPtr);

		Timing::getInstance()->print();
	}

	Cleanup();
}
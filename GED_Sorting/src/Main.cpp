#include <assert.h>
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

const size_t IntCacheSize = 1000;
const size_t IntRamSize = 10000;
const size_t ObjectCacheSize = 1000;
const size_t ObjectRamSize = 10000;

int* IntCache;
int* IntRam;
ComplexObject* ObjectCache;
ComplexObject* ObjectRam;

int** IntPtrCache;
int** IntPtrRam;
ComplexObject** ObjectPtrCache;
ComplexObject** ObjectPtrRam;

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

	int* bubbleCopy = new int[IntCacheSize];
	CopyArray(IntCache, bubbleCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Bubble", true);
	BubbleSort::Sort(bubbleCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	int* insertCopy = new int[IntCacheSize];
	CopyArray(IntCache, insertCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Insertion", true);
	InsertionSort::Sort(insertCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	int* quickCopy = new int[IntCacheSize];
	CopyArray(IntCache, quickCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Quick", true);
	QuickSort::Sort(quickCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	int* bucketCopy = new int[IntCacheSize];
	CopyArray(IntCache, bucketCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Bucket", true);
	BucketSort::Sort(bucketCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant2()
{
	std::string variant("Variant 2 - ");

	int* bubbleCopy = new int[IntRamSize];
	CopyArray(IntRam, bubbleCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Bubble", true);
	BubbleSort::Sort(bubbleCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	int* insertCopy = new int[IntRamSize];
	CopyArray(IntRam, insertCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Insertion", true);
	InsertionSort::Sort(insertCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	int* quickCopy = new int[IntRamSize];
	CopyArray(IntRam, quickCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Quick", true);
	QuickSort::Sort(quickCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	int* bucketCopy = new int[IntRamSize];
	CopyArray(IntRam, bucketCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Bucket");
	BucketSort::Sort(bucketCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant3()
{
	std::string variant("Variant 3 - ");

	ComplexObject* bubbleCopy = new ComplexObject[IntCacheSize];
	CopyArray(ObjectCache, bubbleCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Bubble", true);
	BubbleSort::Sort(bubbleCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	ComplexObject* insertCopy = new ComplexObject[IntCacheSize];
	CopyArray(ObjectCache, insertCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Insertion", true);
	InsertionSort::Sort(insertCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	ComplexObject* quickCopy = new ComplexObject[IntCacheSize];
	CopyArray(ObjectCache, quickCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Quick", true);
	QuickSort::Sort(quickCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	ComplexObject* bucketCopy = new ComplexObject[IntCacheSize];
	CopyArray(ObjectCache, bucketCopy, IntCacheSize);
	Timing::getInstance()->startRecord(variant + "Bucket", true);
	BucketSort::Sort(bucketCopy, IntCacheSize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant4()
{
	std::string variant("Variant 4 - ");
}

void Variant5()
{
	std::string variant("Variant 5 - ");

	ComplexObject* bubbleCopy = new ComplexObject[IntRamSize];
	CopyArray(ObjectRam, bubbleCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Bubble", true);
	BubbleSort::Sort(bubbleCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Bubble");
	delete[] bubbleCopy;

	ComplexObject* insertCopy = new ComplexObject[IntRamSize];
	CopyArray(ObjectRam, insertCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Insertion", true);
	InsertionSort::Sort(insertCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Insertion");
	delete[] insertCopy;

	ComplexObject* quickCopy = new ComplexObject[IntRamSize];
	CopyArray(ObjectRam, quickCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Quick", true);
	QuickSort::Sort(quickCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Quick");
	delete[] quickCopy;

	ComplexObject* bucketCopy = new ComplexObject[IntRamSize];
	CopyArray(ObjectRam, bucketCopy, IntRamSize);
	Timing::getInstance()->startRecord(variant + "Bucket", true);
	BucketSort::Sort(bucketCopy, IntRamSize);
	Timing::getInstance()->stopRecord(variant + "Bucket");
	delete[] bucketCopy;
}

void Variant6()
{
	std::string variant("Variant 6 - ");
}

void Variant7()
{
	std::string variant("Variant 7 - ");
}

void Variant8()
{
	std::string variant("Variant 8 - ");
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

void VerifyIntSorting()
{
	int* stdCopy = new int[IntCacheSize];
	CopyArray(IntCache, stdCopy, IntCacheSize);
	std::sort(stdCopy, stdCopy + IntCacheSize);

	std::cout << "Verifying Int Bubble" << std::endl;
	int* bubbleCopy = new int[IntCacheSize];
	CopyArray(IntCache, bubbleCopy, IntCacheSize);
	BubbleSort::Sort(bubbleCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == bubbleCopy[i]);
	}
	delete[] bubbleCopy;

	std::cout << "Verifying Int Insert" << std::endl;
	int* insertCopy = new int[IntCacheSize];
	CopyArray(IntCache, insertCopy, IntCacheSize);
	InsertionSort::Sort(insertCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == insertCopy[i]);
	}
	delete[] insertCopy;

	std::cout << "Verifying Int Quick" << std::endl;
	int* quickCopy = new int[IntCacheSize];
	CopyArray(IntCache, quickCopy, IntCacheSize);
	QuickSort::Sort(quickCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == quickCopy[i]);
	}
	QuickSort::Sort(quickCopy, IntCacheSize);
	delete[] quickCopy;

	std::cout << "Verifying Int Bucket" << std::endl;
	int* bucketCopy = new int[IntCacheSize];
	CopyArray(IntCache, bucketCopy, IntCacheSize);
	BucketSort::Sort(bucketCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == bucketCopy[i]);
	}
	delete[] bucketCopy;

	delete[] stdCopy;
}

void VerifyIntPtrSorting()
{
	int** stdCopy = new int*[IntCacheSize];
	CopyArray(IntPtrCache, stdCopy, IntCacheSize);
	std::sort(stdCopy, stdCopy + IntCacheSize);

	std::cout << "Verifying IntPtr Bubble" << std::endl;
	int** bubbleCopy = new int*[IntCacheSize];
	CopyArray(IntPtrCache, bubbleCopy, IntCacheSize);
	BubbleSort::Sort(bubbleCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == bubbleCopy[i]);
	}
	delete[] bubbleCopy;

	std::cout << "Verifying IntPtr Insert" << std::endl;
	int** insertCopy = new int*[IntCacheSize];
	CopyArray(IntPtrCache, insertCopy, IntCacheSize);
	InsertionSort::Sort(insertCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == insertCopy[i]);
	}
	delete[] insertCopy;

	std::cout << "Verifying IntPtr Quick" << std::endl;
	int** quickCopy = new int*[IntCacheSize];
	CopyArray(IntPtrCache, quickCopy, IntCacheSize);
	QuickSort::Sort(quickCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == quickCopy[i]);
	}
	QuickSort::Sort(quickCopy, IntCacheSize);
	delete[] quickCopy;

	std::cout << "Verifying IntPtr Bucket" << std::endl;
	int** bucketCopy = new int*[IntCacheSize];
	CopyArray(IntPtrCache, bucketCopy, IntCacheSize);
	BucketSort::Sort(bucketCopy, IntCacheSize);
	for (size_t i = 0; i < IntCacheSize; i++)
	{
		assert(stdCopy[i] == bucketCopy[i]);
	}
	delete[] bucketCopy;

	delete[] stdCopy;
}

void VerifyObjectSorting()
{
	ComplexObject* stdCopy = new ComplexObject[ObjectCacheSize];
	CopyArray(ObjectCache, stdCopy, ObjectCacheSize);
	std::sort(stdCopy, stdCopy + ObjectCacheSize);

	std::cout << "Verifying Object Bubble" << std::endl;
	ComplexObject* bubbleCopy = new ComplexObject[ObjectCacheSize];
	CopyArray(ObjectCache, bubbleCopy, ObjectCacheSize);
	BubbleSort::Sort(bubbleCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == bubbleCopy[i]);
	}
	delete[] bubbleCopy;

	std::cout << "Verifying Object Insert" << std::endl;
	ComplexObject* insertCopy = new ComplexObject[ObjectCacheSize];
	CopyArray(ObjectCache, insertCopy, ObjectCacheSize);
	InsertionSort::Sort(insertCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == insertCopy[i]);
	}
	delete[] insertCopy;

	std::cout << "Verifying Object Quick" << std::endl;
	ComplexObject* quickCopy = new ComplexObject[ObjectCacheSize];
	CopyArray(ObjectCache, quickCopy, ObjectCacheSize);
	QuickSort::Sort(quickCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == quickCopy[i]);
	}
	QuickSort::Sort(quickCopy, ObjectCacheSize);
	delete[] quickCopy;

	std::cout << "Verifying Object Bucket" << std::endl;
	ComplexObject* bucketCopy = new ComplexObject[ObjectCacheSize];
	CopyArray(ObjectCache, bucketCopy, ObjectCacheSize);
	BucketSort::Sort(bucketCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == bucketCopy[i]);
	}
	delete[] bucketCopy;

	delete[] stdCopy;
}

void VerifyObjectPtrSorting()
{
	ComplexObject** stdCopy = new ComplexObject*[ObjectCacheSize];
	CopyArray(ObjectPtrCache, stdCopy, ObjectCacheSize);
	std::sort(stdCopy, stdCopy + ObjectCacheSize);

	std::cout << "Verifying ObjectPtr Bubble" << std::endl;
	ComplexObject** bubbleCopy = new ComplexObject*[ObjectCacheSize];
	CopyArray(ObjectPtrCache, bubbleCopy, ObjectCacheSize);
	BubbleSort::Sort(bubbleCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == bubbleCopy[i]);
	}
	delete[] bubbleCopy;

	std::cout << "Verifying ObjectPtr Insert" << std::endl;
	ComplexObject** insertCopy = new ComplexObject*[ObjectCacheSize];
	CopyArray(ObjectPtrCache, insertCopy, ObjectCacheSize);
	InsertionSort::Sort(insertCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == insertCopy[i]);
	}
	delete[] insertCopy;

	std::cout << "Verifying ObjectPtr Quick" << std::endl;
	ComplexObject** quickCopy = new ComplexObject*[ObjectCacheSize];
	CopyArray(ObjectPtrCache, quickCopy, ObjectCacheSize);
	QuickSort::Sort(quickCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == quickCopy[i]);
	}
	QuickSort::Sort(quickCopy, ObjectCacheSize);
	delete[] quickCopy;

	std::cout << "Verifying ObjectPtr Bucket" << std::endl;
	ComplexObject** bucketCopy = new ComplexObject*[ObjectCacheSize];
	CopyArray(ObjectPtrCache, bucketCopy, ObjectCacheSize);
	BucketSort::Sort(bucketCopy, ObjectCacheSize);
	for (size_t i = 0; i < ObjectCacheSize; i++)
	{
		assert(stdCopy[i] == bucketCopy[i]);
	}
	delete[] bucketCopy;

	delete[] stdCopy;
}

void VerifySorting()
{
	VerifyIntSorting();
	VerifyIntPtrSorting();
	VerifyObjectSorting();
	VerifyObjectPtrSorting();
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
		Variant1();
		Variant2();
		Variant3();
		Variant4();
		Variant5();
		Variant6();
		Variant7();
		Variant8();

		Timing::getInstance()->print();
	}

	Cleanup();
}
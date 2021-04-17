#pragma once

#include <algorithm>

namespace QuickSort
{
	template<typename T>
	T* Partition(T*, T* begin, T* end)
	{
        T* pivot = end;
        T* i = begin;

        for (T* j = begin; j < end; j++)
        {
            if (*j < *pivot)
            {
                std::swap(*i, *j);
                i++;
            }
        }
        std::swap(*i, *end);
        return i;
	}

	template<typename T>
	void QuickSort(T* arr, T* begin, T* end)
	{
        if (begin < end)
        {
            T* pi = Partition(arr, begin, end);
            QuickSort(arr, begin, pi - 1);
            QuickSort(arr, pi + 1, end);
        }
	}

    template<typename T>
    void Sort(T* arr, size_t size)
    {
        QuickSort(arr, arr, arr + size - 1);
    }
}

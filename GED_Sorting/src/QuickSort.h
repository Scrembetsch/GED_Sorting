#pragma once

#include <algorithm>

namespace QuickSort
{
	template<typename T>
	size_t Partition(T* arr, size_t begin, size_t end)
	{
        size_t pivot = end;
        size_t i = begin;

        for (size_t j = begin; j < end; j++)
        {
            if (arr[j] < arr[pivot])
            {
                std::swap(arr[i], arr[j]);
                i++;
            }
        }
        std::swap(arr[i], arr[end]);
        return i;
	}

	template<typename T>
	void QuickSort(T* arr, size_t begin, size_t end)
	{
        if (begin < end)
        {
            size_t pi = Partition(arr, begin, end);
            if (pi > 0) // If is needed because size_t can underflow
            {
                QuickSort(arr, begin, pi - 1);
            }
            QuickSort(arr, pi + 1, end);
        }
	}

    template<typename T>
    void Sort(T* arr, size_t size)
    {
        QuickSort(arr, 0, size - 1);
    }
}

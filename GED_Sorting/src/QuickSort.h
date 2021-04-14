#pragma once

#include <algorithm>

namespace QuickSort
{
	template<typename T>
	size_t Partition(T* arr, size_t begin, size_t end)
	{
        T* pivot = &arr[end];
        size_t i = begin - 1;

        for (size_t j = begin; j < end; j++)
        {
            if (arr[j] <= *pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[end]);
        return (i + 1);
	}

	template<typename T>
	void QuickSort(T* arr, size_t begin, size_t end)
	{
        if (begin < end)
        {
            size_t pi = Partition(arr, begin, end);
            if (pi > 0)
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

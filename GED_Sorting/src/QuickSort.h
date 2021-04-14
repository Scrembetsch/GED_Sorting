#pragma once

#include <algorithm>

namespace QuickSort
{
	template<typename T>
	size_t Partition(T* arr, size_t begin, size_t end)
	{
        T* pivot = &arr[end];    // pivot
        int i = (begin - 1);  // Index of smaller element

        for (size_t j = begin; j <= end - 1; j++)
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
	void Sort(T* arr, size_t begin, size_t end)
	{
        if (begin < end)
        {
            int pi = Partition(arr, begin, end);
            Sort(arr, begin, pi - 1);
            Sort(arr, pi + 1, end);
        }
	}
}

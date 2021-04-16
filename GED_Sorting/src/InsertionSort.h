#pragma once

namespace InsertionSort
{
    template<typename T>
    void Sort(T* arr, size_t size)
    {
        size_t curr;
        for (int i = 0; i < size - 1; i++)
        {
            curr = i + 1;
            while (curr > 0 && arr[curr] < arr[curr - 1])
            {
                std::swap(arr[curr], arr[curr - 1]);
                curr--;
            }
        }
    }
}
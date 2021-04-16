#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

namespace BucketSort
{
    template<typename T>
    void BucketSort(T* arr, size_t n)
    {

        // 1) Create n empty buckets
        std::vector<T>* b = new std::vector<T>[n+1];

        // 2) Put array elements
        // in different buckets
        T min = arr[0];
        T max = arr[0];
        for (size_t i = 0; i < n; i++)
        {
            min = std::min(arr[i], min);
            max = std::max(arr[i], max);
        }

        float range = (size_t(max) - size_t(min)) / n + 1;

        for (size_t i = 0; i < n; i++) {
            size_t bi = (size_t(arr[i]) - size_t(min)) / range; // Index in bucket
            b[bi].push_back(arr[i]);
        }

        // 3) Sort individual buckets
        for (int i = 0; i < n; i++)
            std::sort(b[i].begin(), b[i].end());

        // 4) Concatenate all buckets into arr[]
        int index = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b[i].size(); j++)
                arr[index++] = b[i][j];
    }

    template<typename T>
    void Sort(T* arr, size_t size)
    {
        BucketSort(arr, size);
    }
}
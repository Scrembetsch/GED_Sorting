#pragma once

namespace Sort
{

    template<typename D = void>
    struct Lesser
    {
        template<typename T>
        bool operator()(const T& a, const T& b) const
        {
            return a < b;
        }
    };

    template<typename D = void>
    struct LesserPtr
    {
        template<typename T>
        bool operator()(const T& a, const T& b) const
        {
            return *a < *b;
        }
    };
}

namespace BubbleSort
{
    template<typename T, typename C>
    void Sort(T* arr, size_t size, C compare)
    {
        std::sort(arr, arr + size, compare);
    }
}

namespace InsertionSort
{
    template<typename T, typename C>
    void Sort(T* arr, size_t size, C compare)
    {
        size_t curr;
        for (size_t i = 0; i < size - 1; i++)
        {
            curr = i + 1;
            while (curr > 0 && compare(arr[curr], arr[curr - 1]))
            {
                std::swap(arr[curr], arr[curr - 1]);
                curr--;
            }
        }
    }
}

namespace QuickSort
{
    template<typename T, typename C>
    T* Partition(T* begin, T* end, C compare)
    {
        T* pivot = end;
        T* i = begin;

        for (T* j = begin; j < end; j++)
        {
            if (compare(*j, *pivot))
            {
                std::swap(*i, *j);
                i++;
            }
        }
        std::swap(*i, *end);
        return i;
    }

    template<typename T, typename C>
    void QuickSort(T* begin, T* end, C compare)
    {
        if (begin < end)
        {
            T* pi = Partition(begin, end, compare);
            QuickSort(begin, pi - 1, compare);
            QuickSort(pi + 1, end, compare);
        }
    }

    template<typename T, typename C>
    void Sort(T* arr, size_t size, C compare)
    {
        QuickSort(arr, arr + size - 1, compare);
    }
}

namespace BucketSort
{
    template<typename T, typename C>
    void BucketSort(T* arr, size_t n, C compare)
    {

        // 1) Create n empty buckets
        std::vector<T>* b = new std::vector<T>[n + 1];

        // 2) Put array elements
        // in different buckets
        T min = arr[0];
        T max = arr[0];
        for (size_t i = 0; i < n; i++)
        {
            min = compare(arr[i], min) ? arr[i] : min;
            max = compare(arr[i], max) ? max : arr[i];
        }

        float range = (size_t(max) - size_t(min)) / n + 1;

        for (size_t i = 0; i < n; i++)
        {
            size_t bi = (size_t(arr[i]) - size_t(min)) / range; // Index in bucket
            b[bi].push_back(arr[i]);
        }

        // 3) Sort individual buckets
        for (size_t i = 0; i < n; i++)
            std::sort(b[i].begin(), b[i].end(), compare);

        // 4) Concatenate all buckets into arr[]
        size_t index = 0;
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < b[i].size(); j++)
                arr[index++] = b[i][j];

        delete[] b;
    }

    template<typename T, typename C>
    void Sort(T* arr, size_t size, C compare)
    {
        BucketSort(arr, size, compare);
    }
}
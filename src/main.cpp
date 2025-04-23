#include "Sorts.h"
#include <chrono>
#include <random>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration;

    int max_int = 100000;
    int listSize = 10000;
    std::random_device dev;
    std::mt19937_64 rng(dev());
    std::uniform_int_distribution<std::mt19937_64::result_type> dist(0, max_int);
    std::vector<int> OrigList;
    for (int i = 0; i < listSize; i++)
    {
        OrigList.push_back(dist(rng));
    }
    std::vector<int> insertionList = OrigList;
    std::vector<int> bubbleList = OrigList;
    std::vector<int> quickList = OrigList;
    std::vector<int> mergeList = OrigList;
    std::vector<int> countList = OrigList;
    std::vector<int> radixList = OrigList;
    std::vector<int> bucketList = OrigList;
    
    std::cout << "== INSERTION SORT ==" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    insertionSort(insertionList);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (!isSorted(insertionList))
    {
        std::cout << "INSERTIONSORT FAILURE!!! LIST NOT SORTED" << std::endl;
    }
    else
    {
        std::cout << "TIME TO COMPLETE: " << duration.count() << " microseconds" << std::endl;
    }

    std::cout << "== BUBBLE SORT ==" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    bubbleSort(bubbleList);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (!isSorted(bubbleList))
    {
        std::cout << "BUBBLESORT FAILURE!!! LIST NOT SORTED" << std::endl;
    }
    else
    {
        std::cout << "TIME TO COMPLETE: " << duration.count() << " microseconds" << std::endl;
    }

    std::cout << "== QUICK SORT ==" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    quickSort(quickList, 0, quickList.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (!isSorted(quickList))
    {
        std::cout << "QUICKSORT FAILURE!!! LIST NOT SORTED" << std::endl;
    }
    else
    {    
        std::cout << "TIME TO COMPLETE: " << duration.count() << " microseconds" << std::endl;
    }

    std::cout << "== MERGE SORT ==" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    mergeSort(mergeList, 0, mergeList.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (!isSorted(mergeList))
    {
        std::cout << "MERGESORT FAILURE!!! LIST NOT SORTED" << std::endl;
    }
    else
    {    
        std::cout << "TIME TO COMPLETE: " << duration.count() << " microseconds" << std::endl;
    }

    std::cout << "== RADIX SORT (BASE 10) ==" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    radixSort(radixList);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (!isSorted(radixList))
    {
        std::cout << "RADIXSORT FAILURE!!! LIST NOT SORTED" << std::endl;
    }
    else
    {    
        std::cout << "TIME TO COMPLETE: " << duration.count() << " microseconds" << std::endl;
    }

    std::cout << "== COUNTING SORT ==" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    countingSort(countList);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (!isSorted(countList))
    {
        std::cout << "COUNTINGSORT FAILURE!!! LIST NOT SORTED" << std::endl;
    }
    else
    {    
        std::cout << "TIME TO COMPLETE: " << duration.count() << " microseconds" << std::endl;
    }

    std::cout << "== BUCKET SORT ==" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    bucketSort(bucketList);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (!isSorted(bucketList))
    {
        std::cout << "BUCKETSORT FAILURE!!! LIST NOT SORTED" << std::endl;
    }
    else
    {    
        std::cout << "TIME TO COMPLETE: " << duration.count() << " microseconds" << std::endl;
    }
}
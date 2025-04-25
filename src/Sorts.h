#pragma once
#include <cmath>
#include <vector>
#include <iostream>

extern "C"
{
    struct MaxMin
    {
        int max;
        int min;
    };

    /**
      * @brief Iterative maxMin function
      * @param list: vector of integers
      * @returns MaxMin struct
      */
    MaxMin maxMin(std::vector<int> list);

    /**
      * @brief Logs contents of list to console
      * @param list: vector of integers
      * @returns none
      */
    void print(std::vector<int>& list);
    
    /**
      * @brief Wrapper for isSorted test
      * @param arr: array of integers
      * @param length: length of array
      * @returns result of isSorted
      */
    bool isSortedRaw(int* arr, int length);
    
    /**
      * @brief Test if list is sorted
      * @param list: vector of integers
      * @returns true if list is sorted else false
      */
    bool isSorted(std::vector<int>& list);

    /**
      * @brief Wrapper for insertion sort
      * @param arr: array of integers
      * @param length: length of array
      * @returns none
      */
    void insertionSortRaw(int* arr, int length);
    
    /**
      * @brief Sorts a vector of integers using the insertion sort algorithm
      * @param list: vector of integers
      * @returns none
      */
    void insertionSort(std::vector<int>& list);
    
    /**
      * @brief Wrapper for selection sort
      * @param arr: array of integers
      * @param length: length of array
      * @returns none
      */
    void selectionSortRaw(int* arr, int length);
    
    /**
      * @brief Sorts a vector of integers using the selection sort algorithm
      * @param list: vector of integers
      * @returns none
      */
    void selectionSort(std::vector<int>&);

    /**
      * @brief Wrapper for bubble sort
      * @param arr: array of integers
      * @param length: length of array
      * @returns none
      */
    void bubbleSortRaw(int* arr, int length);
    
    /**
      * @brief Sorts a vector of integers using the bubble sort algorithm
      * @param list: vector of integers
      * @returns none
      */
    void bubbleSort(std::vector<int>&);
    
    /**
      * @brief Partitions list for quick sort
      * @param list: vector of integers
      * @param start: integer starting position
      * @param end: integer ending position
      * @returns integer pivot point
      */
    int partition(std::vector<int>&, int, int);

    /**
      * @brief Wrapper for quick sort
      * @param arr: array of integers
      * @param length: length of array
      * @returns none
      */
    void quickSortRaw(int* arr, int length);
    
    /**
      * @brief Sorts a vector of integers using the quick sort algorithm
      * @param list: vector of integers
      * @param start: integer starting position
      * @param end: integer ending position
      * @returns none
      */
    void quickSort(std::vector<int>& list, int start, int end);
    
    /**
      * @brief Wrapper for merge sort
      * @param arr: array of integers
      * @param length: length of array
      * @returns none
      */
    void mergeSortRaw(int* arr, int length);
    
    /**
      * @brief Partitions list for quick sort
      * @param list: vector of integers
      * @param start: integer starting position
      * @param mid: integer middle position
      * @param end: integer ending position
      * @returns none
      */
    void merge(std::vector<int>& list, int start, int mid, int end);
    
    /**
      * @brief Sorts a vector of integers using the merge sort algorithm
      * @param list: vector of integers
      * @param start: integer starting position
      * @param end: integer ending position
      * @returns none
      */
    void mergeSort(std::vector<int>& list, int start, int end);
    
    /**
      * @brief Wrapper for radix sort
      * @param arr: array of integers
      * @param length: length of array
      * @returns none
      */
    void radixSortRaw(int* arr, int length);
    
    /**
      * @brief Sorts a vector of integers using the base 10 radix sort algorithm
      * @param list: vector of integers
      * @returns none
      */
    void radixSort(std::vector<int>& list);
    
    /**
      * @brief Wrapper for counting sort
      * @param arr: array of integers
      * @param length: length of array
      * @returns none
      */
    void countingSortRaw(int* arr, int length);
    
    /**
      * @brief Sorts a vector of integers using the counting sort algorithm
      * @param list: vector of integers
      * @returns none
      */
    void countingSort(std::vector<int>& list);
}
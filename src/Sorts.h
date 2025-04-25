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

    MaxMin maxMin(std::vector<int>);

    void print(std::vector<int>& list);
    bool isSortedRaw(int* arr, int length);
    bool isSorted(std::vector<int>& list);

    void insertionSortRaw(int* arr, int length);
    void insertionSort(std::vector<int>&);
    void selectionSortRaw(int* arr, int length);
    void selectionSort(std::vector<int>&);
    void bubbleSortRaw(int* arr, int length);
    void bubbleSort(std::vector<int>&);
    int partition(std::vector<int>&, int, int);
    void quickSortRaw(int* arr, int length);
    void quickSort(std::vector<int>&, int, int);
    void mergeSortRaw(int* arr, int length);
    void merge(std::vector<int>&, int, int, int);
    void mergeSort(std::vector<int>&, int, int);
    void radixSortRaw(int* arr, int length);
    void radixSort(std::vector<int>&);
    void countingSortRaw(int* arr, int length);
    void countingSort(std::vector<int>&);
    void bucketSortRaw(int* arr, int length);
    void bucketSort(std::vector<int>&);
}
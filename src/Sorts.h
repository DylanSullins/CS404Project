#pragma once
#include <cmath>
#include <vector>
#include <iostream>

#include "Sorts.h"
struct MaxMin
{
    int max;
    int min;
};

MaxMin maxMin(std::vector<int>);
void insertionSort(std::vector<int>&);
void selectionSort(std::vector<int>&);
void bubbleSort(std::vector<int>&);
int partition(std::vector<int>&, int, int);
void quickSort(std::vector<int>&, int, int);
void merge(std::vector<int>&, int, int, int);
void mergeSort(std::vector<int>&, int, int);
void radixSort(std::vector<int>&);
void countingSort(std::vector<int>&);
void bucketSort(std::vector<int>&);
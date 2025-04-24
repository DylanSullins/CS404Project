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

void insertionSortStep(std::vector<int>&);
void selectionSortStep(std::vector<int>&);
void bubbleSortStep(std::vector<int>&);
int partitionStep(std::vector<int>&, int, int);
void quickSortStep(std::vector<int>&, int, int);
void mergeStep(std::vector<int>&, int, int, int);
void mergeSortStep(std::vector<int>&, int, int);
void radixSortStep(std::vector<int>&);
void countingSortStep(std::vector<int>&);
void bucketSortStep(std::vector<int>&);
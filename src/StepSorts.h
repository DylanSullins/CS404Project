#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
extern "C"
{
    // COMPARISON SORTS
    struct ComparisonSortState
    {
        std::vector<int> data;
        int i, j, mindex;
        bool done;
        int* externalData;
    };

    ComparisonSortState* insertionSortInit(int * arr, int length);
    bool insertionSortStep(ComparisonSortState* state);
    void insertionSortFree(ComparisonSortState* state);

    ComparisonSortState* selectionSortInit(int * arr, int length);
    bool selectionSortStep(ComparisonSortState* state);
    void selectionSortFree(ComparisonSortState* state);

    ComparisonSortState* bubbleSortInit(int * arr, int length);
    bool bubbleSortStep(ComparisonSortState* state);
    void bubbleSortFree(ComparisonSortState* state);

    
    // QUICK SORT
    struct QuickSortTask
    {
        int start;
        int end;
    };
    struct QuickSortState
    {
        std::vector<int> data;
        int* externalData;
        std::vector<QuickSortTask> stack;
        bool isPartitioning = false;
        int pivot;
        int low;
        int high;
        int start;
        int end;
        bool done = false;
    };

    QuickSortState* quickSortInit(int* arr, int length);
    bool quickSortStep(QuickSortState* state);
    void quickSortFree(QuickSortState* state);


    // Merge Sort
    enum class MergeTaskType
    {
        SPLIT,
        MERGE
    };
    struct MergeTask
    {
        MergeTaskType type;
        int start;
        int mid;
        int end;
    };
    struct MergeSortState
    {
        std::vector<int> data;
        int* externalData;

        std::stack<MergeTask> tasks;
        std::vector<int> temp;
        int i, j, k;
        bool isMerging = false;
        MergeTask currentTask;
        bool done = false;
    };

    MergeSortState* mergeSortInit(int* arr, int length);
    bool mergeSortStep(MergeSortState* state);
    void mergeSortFree(MergeSortState* state);


    // TODO: IMPLEMENT THE REST OF THE SORTS STEP BY STEP FOR USE WITH PYGAME
    void placeSortStep(std::vector<int>& list, int place);

    void radixSortStep(std::vector<int>& list);

    void countingSortStep(std::vector<int>& list);

    void bucketSortStep(std::vector<int>& list);
}
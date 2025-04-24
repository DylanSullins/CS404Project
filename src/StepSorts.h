#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
extern "C"
{
    struct MaxMin
    {
        int max;
        int min;
    };

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

    int comparisonSortGetHighlightI(ComparisonSortState* state);
    int comparisonSortGetHighlightJ(ComparisonSortState* state);
    int comparisonSortGetHighlightWrite(ComparisonSortState* state);

    
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
        int highlight_i = -1, highlight_j = -1, highlight_write = -1;
        bool done = false;
    };

    QuickSortState* quickSortInit(int* arr, int length);
    bool quickSortStep(QuickSortState* state);
    int quickSortGetHighlightI(QuickSortState* state);
    int quickSortGetHighlightJ(QuickSortState* state);
    int quickSortGetHighlightWrite(QuickSortState* state);
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
        int highlight_i = -1, highlight_j = -1, highlight_write = -1;
        bool isMerging = false;
        MergeTask currentTask;
        bool done = false;
    };

    MergeSortState* mergeSortInit(int* arr, int length);
    bool mergeSortStep(MergeSortState* state);
    int mergeSortGetHighlightI(MergeSortState* state);
    int mergeSortGetHighlightJ(MergeSortState* state);
    int mergeSortGetHighlightWrite(MergeSortState* state);
    void mergeSortFree(MergeSortState* state);


    // TODO: IMPLEMENT THE REST OF THE SORTS STEP BY STEP FOR USE WITH PYGAME

    // Radix Sort
    struct RadixSortState
    {
        std::vector<int> data;
        std::vector<int> temp;
        std::vector<int> count;
        int* externalData;
        int max, place, phase, index;
        bool done;
    };

    RadixSortState* radixSortInit(int* arr, int length);
    bool radixSortStep(RadixSortState* state);
    void radixSortFree(RadixSortState* state);
    int radixSortGetHighlightWrite(RadixSortState* state);

    // Counting Sort
    struct CountingSortState
    {
        std::vector<int> data;
        std::vector<int> count;
        std::vector<int> output;
        int* externalData;
        int max, phase, index;
        bool done;
    };
    CountingSortState* countingSortInit(int* arr, int length);
    bool countingSortStep(CountingSortState* state);
    void countingSortFree(CountingSortState* state);
    int countingSortGetHighlightWrite(CountingSortState* state);
}
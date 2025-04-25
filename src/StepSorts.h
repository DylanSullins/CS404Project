#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
extern "C"
{
    // Max/Min Helper
    struct MaxMin
    {
        int max;
        int min;
    };
    MaxMin maxMin(std::vector<int> list);

    // COMPARISON SORTS
    struct ComparisonSortState
    {
        std::vector<int> data;
        int i, j, mindex;
        bool done;
        int* externalData;
    };

    /**
      * @brief Initializes insertion sort state
      * @param arr: array of integers
      * @param length: length of array
      * @returns state struct containing sorting data
      */
    ComparisonSortState* insertionSortInit(int * arr, int length);

    /**
      * @brief Step by step insertion sort
      * @param state: state struct containing sorting data
      * @returns bool to continue sorting
      */
    bool insertionSortStep(ComparisonSortState* state);

    /**
      * @brief Frees dynamic memory in sort state
      * @param state: state struct containing sorting data
      * @returns none
      */
    void insertionSortFree(ComparisonSortState* state);

    /**
      * @brief Initializes selection sort state
      * @param arr: array of integers
      * @param length: length of array
      * @returns state struct containing sorting data
      */
    ComparisonSortState* selectionSortInit(int * arr, int length);

    /**
      * @brief Step by step selection sort
      * @param state: state struct containing sorting data
      * @returns bool to continue sorting
      */
    bool selectionSortStep(ComparisonSortState* state);

    /**
      * @brief Frees dynamic memory in sort state
      * @param state: state struct containing sorting data
      * @returns none
      */
    void selectionSortFree(ComparisonSortState* state);

    /**
      * @brief Initializes bubble sort state
      * @param arr: array of integers
      * @param length: length of array
      * @returns state struct containing sorting data
      */
    ComparisonSortState* bubbleSortInit(int * arr, int length);

    /**
      * @brief Step by step bubble sort
      * @param state: state struct containing sorting data
      * @returns bool to continue sorting
      */
    bool bubbleSortStep(ComparisonSortState* state);

    /**
      * @brief Frees dynamic memory in sort state
      * @param state: state struct containing sorting data
      * @returns none
      */
    void bubbleSortFree(ComparisonSortState* state);

    /**
      * @brief Gets first index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int comparisonSortGetHighlightI(ComparisonSortState* state);

    /**
      * @brief Gets second index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int comparisonSortGetHighlightJ(ComparisonSortState* state);

    /**
      * @brief Gets writing index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
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

    /**
      * @brief Initializes quick sort state
      * @param arr: array of integers
      * @param length: length of array
      * @returns state struct containing sorting data
      */
    QuickSortState* quickSortInit(int* arr, int length);

    /**
      * @brief Step by step quick sort
      * @param state: state struct containing sorting data
      * @returns bool to continue sorting
      */
    bool quickSortStep(QuickSortState* state);

    /**
      * @brief Gets first index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int quickSortGetHighlightI(QuickSortState* state);

    /**
      * @brief Gets second index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int quickSortGetHighlightJ(QuickSortState* state);

    /**
      * @brief Gets writing index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int quickSortGetHighlightWrite(QuickSortState* state);

    /**
      * @brief Frees dynamic memory in sort state
      * @param state: state struct containing sorting data
      * @returns none
      */
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

    /**
      * @brief Initializes merge sort state
      * @param arr: array of integers
      * @param length: length of array
      * @returns state struct containing sorting data
      */
    MergeSortState* mergeSortInit(int* arr, int length);

    /**
      * @brief Step by step merge sort
      * @param state: state struct containing sorting data
      * @returns bool to continue sorting
      */
    bool mergeSortStep(MergeSortState* state);

    /**
      * @brief Gets first index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int mergeSortGetHighlightI(MergeSortState* state);

    /**
      * @brief Gets second index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int mergeSortGetHighlightJ(MergeSortState* state);

    /**
      * @brief Gets writing index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int mergeSortGetHighlightWrite(MergeSortState* state);

    /**
      * @brief Frees dynamic memory in sort state
      * @param state: state struct containing sorting data
      * @returns none
      */
    void mergeSortFree(MergeSortState* state);

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

    /**
      * @brief Initializes radix sort state
      * @param arr: array of integers
      * @param length: length of array
      * @returns state struct containing sorting data
      */
    RadixSortState* radixSortInit(int* arr, int length);

    /**
      * @brief Step by step base 10 radix sort
      * @param state: state struct containing sorting data
      * @returns bool to continue sorting
      */
    bool radixSortStep(RadixSortState* state);

    /**
      * @brief Frees dynamic memory in sort state
      * @param state: state struct containing sorting data
      * @returns none
      */
    void radixSortFree(RadixSortState* state);

    /**
      * @brief Gets writing index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
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

    /**
      * @brief Initializes counting sort state
      * @param arr: array of integers
      * @param length: length of array
      * @returns state struct containing sorting data
      */
    CountingSortState* countingSortInit(int* arr, int length);

    /**
      * @brief Step by step counting sort
      * @param state: state struct containing sorting data
      * @returns bool to continue sorting
      */
    bool countingSortStep(CountingSortState* state);

    /**
      * @brief Frees dynamic memory in sort state
      * @param state: state struct containing sorting data
      * @returns none
      */
    void countingSortFree(CountingSortState* state);

    /**
      * @brief Gets writing index to highlight
      * @param state: state struct containing sorting data
      * @returns integer index to highlight
      */
    int countingSortGetHighlightWrite(CountingSortState* state);
}
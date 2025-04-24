#include "StepSorts.h"

void insertionSortStep(std::vector<int>& list)
{
    int i, j;
    for (i = 0; i < list.size(); ++i)
    {
        j = i;
        while (j > 0 && list[j] < list[j-1])
        {
            std::swap(list[j], list[j-1]);
            --j;
        }
    }
}

void selectionSortStep(std::vector<int>& list)
{
    int i, j, mindex;
    for (i = 0; i < list.size(); ++i)
    {
        mindex = i;
        for (j = i + 1; j < list.size(); ++j)
        {
            if (list[j] < list[mindex]) mindex = j;
        }
        std::swap(list[i], list[mindex]);
    }
}


void bubbleSortStep(std::vector<int>& list)
{
    int i, j;
    for (i = list.size() - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (list[j] > list[j+1]) {
                std::swap(list[j], list[j+1]);
            }
        }
    }
}

int partitionStep(std::vector<int>& list, int start, int end)
{
    int pivot = list[(start + end) / 2];
    int low = start;
    int high = end;
    bool done = false;
    while (!done) 
    {
        while (list[low] < pivot)
        {
            ++low;
        }
        while (list[high] > pivot)
        {
            --high;
        }
        if (low >= high)
        {
            done = true;
        }
        else 
        {
            std::swap(list[low], list[high]);
            ++low;
            --high;
        }
    }
    return high;
}

void quickSortStep(std::vector<int>& list, int start, int end)
{
    if (start >= end) {return;}
    int p = partitionStep(list, start, end);
    quickSortStep(list, start, p);
    quickSortStep(list, p + 1, end);
}

void mergeStep(std::vector<int>& list, int start, int mid, int end)
{
    std::vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (list[i] < list[j])
        {
            temp[k++] = list[i++];
        }
        else
        {
            temp[k++] = list[j++];
        }
    }
    while (i <= mid) temp[k++] = list[i++];
    while (j <= end) temp[k++] = list[j++];
    for (int t = 0; t < temp.size(); ++t)
    {
        list[start + t] = temp[t];
    }
}

void mergeSortStep(std::vector<int>& list, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSortStep(list, start, mid);
    mergeSortStep(list, mid+1, end);
    mergeStep(list, start, mid, end);
}

void placeSortStep(std::vector<int>& list, int place) 
{
    std::vector<int> tempList(list.size());
    std::vector<int> placeCount(10);
    int i;

    for (i = 0; i < list.size(); i++) 
    {
        placeCount[(list[i] / place) % 10]++;
    }

    for (i = 1; i < 10; i++) 
    {
        placeCount[i] += placeCount[i - 1];
    }

    for (i = list.size() - 1; i >= 0; i--) 
    {
        tempList[placeCount[(list[i] / place) % 10] - 1] = list[i];
        placeCount[(list[i] / place) % 10]--;
    }

    for (i = 0; i < list.size(); i++) {
        list[i] = tempList[i];
    }
}

void radixSortStep(std::vector<int>& list)
{
    int max = maxMin(list).max;
    for (int place = 1; max / place > 0; place *= 10) 
    {
        placeSortStep(list, place);
    }
}

void countingSortStep(std::vector<int>& list)
{
    int max = maxMin(list).max;
    std::vector<int> count(max + 1);

    for (int element : list) 
    {
        count[element]++;
    }

    for (int i = 1; i < max + 1; i++) 
    {
        count[i] += count[i - 1];
    }

    std::vector<int> sorted(list.size());
    for (int element : list) 
    {
        sorted[count[element] - 1] = element;
        count[element]--;
    }
    list = sorted;
}

void bucketSortStep(std::vector<int>& list)
{
    int num_buckets = std::sqrt(list.size());
    MaxMin maxAndMin = maxMin(list);
    int max = maxAndMin.max;
    int min = maxAndMin.min;
    if (max - min == 0) {return;}
    if (num_buckets > (max - min)) {
        num_buckets = max - min;
    }
    std::vector<std::vector<int>> buckets(num_buckets);

    
    int bucket_size = (max - min + 1) / num_buckets;
    
    for (int element : list) {
        int bucket_index = (element - min) / bucket_size;
        if (bucket_index >= num_buckets) {
            bucket_index = num_buckets - 1;
        }
        buckets.at(bucket_index).push_back(element);
    }
    for (std::vector<int>& bucket : buckets) {
        radixSortStep(bucket);
    }
    
    std::vector<int> sorted;
    for (std::vector<int>& bucket : buckets) {
        sorted.insert(sorted.end(), bucket.begin(), bucket.end());
    }
    list = sorted;
}
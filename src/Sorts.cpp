#include "Sorts.h"

void print(std::vector<int>& list)
{
    int last = list.size() - 1;
    std::cout << "[";
    for (int i = 0; i < last; i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << list[last] << "]" << std::endl;
}

bool isSorted(std::vector<int>& list)
{
    for (int i = 0; i < list.size() - 1; ++i)
    {
        if (list[i] > list[i + 1]) return false;
    }
    return true;
}

void insertionSort(std::vector<int>& list)
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

void selectionSort(std::vector<int>& list)
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


void bubbleSort(std::vector<int>& list)
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

int partition(std::vector<int>& list, int start, int end)
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

void quickSort(std::vector<int>& list, int start, int end)
{
    if (start >= end) {return;}
    int p = partition(list, start, end);
    quickSort(list, start, p);
    quickSort(list, p + 1, end);
}

void merge(std::vector<int>& list, int start, int mid, int end)
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

void mergeSort(std::vector<int>& list, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(list, start, mid);
    mergeSort(list, mid+1, end);
    merge(list, start, mid, end);
}

struct MaxMin
{
    int max;
    int min;
};

MaxMin maxMin(std::vector<int> list)
{
    int max = list[0];
    int min = list[0];
    for (int i = 1; i < list.size(); i++) 
    {
        if (list[i] > max) 
        {
            max = list[i];
        }
        else if (list[i] < min)
        {
            min = list[i];
        }
    }
    return {max, min};
}

void placeSort(std::vector<int>& list, int place) 
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

void radixSort(std::vector<int>& list)
{
    int max = maxMin(list).max;
    for (int place = 1; max / place > 0; place *= 10) 
    {
        placeSort(list, place);
    }
}

void countingSort(std::vector<int>& list)
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

void bucketSort(std::vector<int>& list)
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
        radixSort(bucket);
    }
    
    std::vector<int> sorted;
    for (std::vector<int>& bucket : buckets) {
        sorted.insert(sorted.end(), bucket.begin(), bucket.end());
    }
    list = sorted;
}
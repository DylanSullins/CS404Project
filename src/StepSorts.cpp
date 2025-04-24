#include "StepSorts.h"

extern "C"
{
    ComparisonSortState* insertionSortInit(int * arr, int length)
    {
        ComparisonSortState* state = new ComparisonSortState;
        state->data = std::vector<int>(arr, arr+length);
        state->externalData = arr;
        state->i = 0;
        state->j = 0;
        state->done = false;
        return state;
    }
    bool insertionSortStep(ComparisonSortState* state)
    {
        if (state->i >= state->data.size())
        {
            state->done = true;
            std::copy(state->data.begin(), state->data.end(), state->externalData);
            return false;
        }
        if (state->j > 0)
        {
            if (state->data[state->j] < state->data[state->j - 1])
            {
                std::swap(state->data[state->j], state->data[state->j - 1]);
                state->j--;
            }
            else
            {
                state->i++;
                state->j = state->i;
            }
        }
        else
        {
            state->i++;
            state->j = state->i;
        }
        std::copy(state->data.begin(), state->data.end(), state->externalData);
        return true;
    }
    void insertionSortFree(ComparisonSortState* state)
    {
        delete state;
    }

    

    ComparisonSortState* selectionSortInit(int * arr, int length)
    {
        ComparisonSortState* state = new ComparisonSortState;
        state->data = std::vector<int>(arr, arr + length);
        state->externalData = arr;
        state->i = 0;
        state->j = 1;
        state->done = false;
        state->mindex = 0;
        return state;
    }
    bool selectionSortStep(ComparisonSortState* state)
    {
        if (state->i >= state->data.size())
        {
            if (!state->done) 
            {
                std::copy(state->data.begin(), state->data.end(), state->externalData);
                state->done = true;
            }
            return false;
        }
        if (state->j < state->data.size())
        {
            if (state->data[state->j] < state->data[state->mindex])
            {
                state->mindex = state->j;
            }
            state->j++;
        }
        else
        {
            std::swap(state->data[state->i], state->data[state->mindex]);
            state->i++;
            state->j = state->i + 1;
            state->mindex = state->i;
        }
        std::copy(state->data.begin(), state->data.end(), state->externalData);
        return true;
    }
    void selectionSortFree(ComparisonSortState* state)
    {
        delete state;
    }

    ComparisonSortState* bubbleSortInit(int * arr, int length)
    {
        ComparisonSortState* state = new ComparisonSortState;
        state->data = std::vector<int>(arr, arr+length);
        state->externalData = arr;
        state->i = length - 1;
        state->j = 0;
        state->done = false;
        return state;
    }
    bool bubbleSortStep(ComparisonSortState* state)
    {
        if (state->i <= 0)
        {
            state->done = true;
            std::copy(state->data.begin(), state->data.end(), state->externalData);
            return false;
        }
        
        if (state->j < state->i)
        {
            if (state->data[state->j] > state->data[state->j + 1])
            {
                std::swap(state->data[state->j], state->data[state->j + 1]);
            }
            state->j++;
        }
        else
        {
            state->i--;
            state->j = 0;
        }
        std::copy(state->data.begin(), state->data.end(), state->externalData);
        return true;
    }
    void bubbleSortFree(ComparisonSortState* state)
    {
        delete state;
    }

    int comparisonSortGetHighlightI(ComparisonSortState* state)
    {
        if (!state) return -1;
        if (state->i >= state->data.size()) return -1;
        return state->i;
    }
    int comparisonSortGetHighlightJ(ComparisonSortState* state)
    {
        if (!state) return -1;
        if (state->j >= state->data.size()) return -1;
        return state->j;
    }
    int comparisonSortGetHighlightWrite(ComparisonSortState* state)
    {
        if (!state) return -1;
        if (state->mindex >= state->data.size()) return -1;
        return state->mindex;
    }

    QuickSortState* quickSortInit(int* arr, int length)
    {
        QuickSortState* state = new QuickSortState;
        state->data = std::vector<int>(arr, arr + length);
        state->externalData = arr;
        state->stack.push_back({0, length - 1});
        return state;
    }

    bool quickSortStep(QuickSortState* state)
    {
        if (state->done) return false;
        if (!state->isPartitioning)
        {
            if (state->stack.empty())
            {
                std::copy(state->data.begin(), state->data.end(), state->externalData);
                state->highlight_i = -1;
                state->highlight_j = -1;
                state->highlight_write = -1;
                state->done = true;
                return false;
            }
            state->start = state->stack.back().start;
            state->end = state->stack.back().end;
            state->stack.pop_back();
            state->highlight_i = state->start;
            state->highlight_j = state->end;
            if (state->start >= state->end) return true;

            state->pivot = state->data[(state->start + state->end) / 2];
            state->low = state->start;
            state->high = state->end;
            state->isPartitioning = true;
        }

        while (state->low <= state->high && state->data[state->low] < state->pivot) 
        {
            state->low++;
            state->highlight_i = state->low;
        }
        while(state->low <= state->high && state->data[state->high] > state->pivot) 
        {
            state->high--;
            state->highlight_j = state->high;
        }
        
        if (state->low <= state->high)
        {
            std::swap(state->data[state->low], state->data[state->high]);
            state->low++;
            state->high--;
            std::copy(state->data.begin(), state->data.end(), state->externalData);
            return true;
        }
        int leftStart = state->start;
        int leftEnd = state->high;
        int rightStart = state->low;
        int rightEnd = state->end;

        if (leftStart < leftEnd)
        {
            state->stack.push_back({leftStart, leftEnd});
        }
        if (rightStart < rightEnd)
        {
            state->stack.push_back({rightStart, rightEnd});
        }
        state->isPartitioning = false;
        return true;
    }
    int quickSortGetHighlightI(QuickSortState* state)
    {
        return state->highlight_i;
    }
    int quickSortGetHighlightJ(QuickSortState* state)
    {
        return state->highlight_j;
    }
    int quickSortGetHighlightWrite(QuickSortState* state)
    {
        return state->highlight_write;
    }

    void quickSortFree(QuickSortState* state)
    {
        delete state;
    }

    MergeSortState* mergeSortInit(int* arr, int length)
    {
        MergeSortState* state = new MergeSortState;
        state->data = std::vector<int>(arr, arr + length);
        state->externalData = arr;
        state->tasks.push({MergeTaskType::SPLIT, 0, 0, length - 1});
        return state;
    }

    bool mergeSortStep(MergeSortState* state)
    {
        if (state->done) return false;
        
        
        if (state->isMerging)
        {
            auto& task = state->currentTask;
    
            if (state->i <= task.mid && state->j <= task.end)
            {
                if (state->data[state->i] < state->data[state->j])
                    state->temp[state->k++] = state->data[state->i++];
                else
                    state->temp[state->k++] = state->data[state->j++];
    
                return true;
            }
    
            if (state->i <= task.mid)
                state->temp[state->k++] = state->data[state->i++];
    
            else if (state->j <= task.end)
                state->temp[state->k++] = state->data[state->j++];
    
            else
            {
                for (int t = 0; t < state->temp.size(); ++t)
                    state->data[task.start + t] = state->temp[t];
    
                std::copy(state->data.begin(), state->data.end(), state->externalData);
                state->isMerging = false;
            }
            state->highlight_i = state->i;
            state->highlight_j = state->j;
            state->highlight_write = task.start + state->k;
            return true;
        }
    
        if (state->tasks.empty())
        {
            std::copy(state->data.begin(), state->data.end(), state->externalData);
            state->done = true;
            return false;
        }
    
        MergeTask task = state->tasks.top();
        state->tasks.pop();
        state->highlight_i = state->i;
        state->highlight_j = state->j;
        state->highlight_write = task.start + state->k;
        if (task.type == MergeTaskType::SPLIT)
        {
            if (task.start >= task.end) return true;
    
            int mid = (task.start + task.end) / 2;
            state->tasks.push({MergeTaskType::MERGE, task.start, mid, task.end});
            state->tasks.push({MergeTaskType::SPLIT, mid + 1, 0, task.end});
            state->tasks.push({MergeTaskType::SPLIT, task.start, 0, mid});
            return true;
        }
        else
        {
            state->currentTask = task;
            state->i = task.start;
            state->j = task.mid + 1;
            state->k = 0;
            state->temp = std::vector<int>(task.end - task.start + 1);
            state->isMerging = true;
            return true;
        }
    }

    int mergeSortGetHighlightI(MergeSortState* state)
    {
        return state->highlight_i;
    }
    int mergeSortGetHighlightJ(MergeSortState* state)
    {
        return state->highlight_j;
    }
    int mergeSortGetHighlightWrite(MergeSortState* state)
    {
        return state->highlight_write;
    }

    void mergeSortFree(MergeSortState* state)
    {
        delete state;
    }


    // Radix Sort

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

    RadixSortState* radixSortInit(int* arr, int length)
    {
        RadixSortState* state = new RadixSortState;
        state->data = std::vector<int>(arr, arr + length);
        state->externalData = arr;
        state->max = maxMin(state->data).max;
        state->phase = 0;
        state->index = 0;
        state->place = 1;
        state->count = std::vector<int>(10, 0);
        state->temp = std::vector<int>(length);
        state->done = false;
        return state;
    }

    bool radixSortStep(RadixSortState* state)
    {
        if (state->done) return false;

        int n = state->data.size();

        switch(state->phase)
        {
            case 0:
                if (state->index < n)
                {
                    int digit = (state->data[state->index] / state->place) % 10;
                    state->count[digit]++;
                    state->index++;
                    return true;
                }
                state->phase = 1;
                state->index = 1;
                return true;
            case 1:
                if (state->index < 10)
                {
                    state->count[state->index] += state->count[state->index - 1];
                    state->index++;
                    return true;
                }
                state->phase = 2;
                state->index = n - 1;
                return true;
            case 2:
                if (state->index >= 0)
                {
                    int digit = (state->data[state->index] / state->place) % 10;
                    state->temp[state->count[digit] - 1] = state->data[state->index];
                    state->count[digit]--;
                    state->index--;
                    return true;
                }
                state->phase = 3;
                state->index = 0;
                return true;
            case 3:
                if (state->index < n)
                {
                    state->data[state->index] = state->temp[state->index];
                    state->index++;
                    std::copy(state->data.begin(), state->data.end(), state->externalData);
                    return true;
                }
                state->place *= 10;
                if (state->max / state->place > 0)
                {
                    state->count = std::vector<int>(10, 0);
                    state->temp = std::vector<int>(n);
                    state->phase = 0;
                    state->index = 0;
                    return true;
                }
                else
                {
                    state->done = true;
                    std::copy(state->data.begin(), state->data.end(), state->externalData);
                    return false;
                }
        }
        return false;
    }

    void radixSortFree(RadixSortState* state)
    {
        delete state;
    }

    int radixSortGetHighlightWrite(RadixSortState* state)
    {
        if (!state) return -1;
        if (state->index < 0 || state->index >= state->data.size()) return -1;
        return state->index;
    }

    // Counting Sort
    CountingSortState* countingSortInit(int* arr, int length)
    {
        CountingSortState* state = new CountingSortState;
        state->data = std::vector<int>(arr, arr + length);
        state->externalData = arr;
        state->max = maxMin(state->data).max;
        state->count = std::vector<int>(state->max + 1, 0);
        state->output = std::vector<int>(length);
        state->phase = 0;
        state->index = 0;
        state->done = false;
        return state;
    }
    bool countingSortStep(CountingSortState* state)
    {
        if (state->done) return false;
        int n = state->data.size();
        switch(state->phase)
        {
            case 0:
                if (state->index < n)
                {
                    state->count[state->data[state->index]]++;
                    state->index++;
                    return true;
                }
                state->phase = 1;
                state->index = 1;
                return true;
            case 1:
                if (state->index <= state->max)
                {
                    state->count[state->index] += state->count[state->index - 1];
                    state->index++;
                    return true;
                }
                state->phase = 2;
                state->index = n - 1;
                return true;
            case 2:
                if (state->index >= 0)
                {
                    int val = state->data[state->index];
                    state->output[--state->count[val]] = val;
                    state->index--;
                    return true;
                }
                state->phase = 3;
                state->index = 0;
                return true;
            case 3:
                if (state->index < n)
                {
                    state->data[state->index] = state->output[state->index];
                    state->index++;
                    std::copy(state->data.begin(), state->data.end(), state->externalData);
                    return true;
                }
                state->done = true;
                return false;
        }
        return false;
    }

    void countingSortFree(CountingSortState* state)
    {
        delete state;
    }

    int countingSortGetHighlightWrite(CountingSortState* state)
    {
        if ((state->phase == 2 || state->phase ==3) && state->index < state->data.size())
        {
            return state->index;
        }
        return -1;
    }
}
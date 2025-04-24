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
            }
            state->j--;
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
                state->done = true;
                return false;
            }
            state->start = state->stack.back().start;
            state->end = state->stack.back().end;
            state->stack.pop_back();
            if (state->start >= state->end) return true;

            state->pivot = state->data[(state->start + state->end) / 2];
            state->low = state->start;
            state->high = state->end;
            state->isPartitioning = true;
        }

        while (state->low <= state->high && state->data[state->low] < state->pivot) state->low++;
        while(state->low <= state->high && state->data[state->high] > state->pivot) state->high--;

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

    void mergeSortFree(MergeSortState* state)
    {
        delete state;
    }
}
import ctypes
import os

""" Python Wrapper for C++ State-Based Sorting Algorithms
Wraps C++ implemented sorting algorithms in python classes for use in Visualizer.py
"""

#dll_path = os.path.join(os.path.dirname(__file__), "StepSorts.dll")
dll_path = os.path.join(os.path.dirname(__file__), "vissorts.so")
try:
    sorts = ctypes.CDLL(dll_path)
except OSError as e:
    print("DLL load failed:")
    print(f"Path: {dll_path}")
    print(f"Error: {e}")
    raise

## Comparison Sorts
sorts.comparisonSortGetHighlightI.argtypes = [ctypes.c_void_p]
sorts.comparisonSortGetHighlightI.restype = ctypes.c_int
sorts.comparisonSortGetHighlightJ.argtypes = [ctypes.c_void_p]
sorts.comparisonSortGetHighlightJ.restype = ctypes.c_int
sorts.comparisonSortGetHighlightWrite.argtypes = [ctypes.c_void_p]
sorts.comparisonSortGetHighlightWrite.restype = ctypes.c_int

### Bubble Sort
sorts.bubbleSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.bubbleSortInit.restype = ctypes.c_void_p
sorts.bubbleSortStep.argtypes = [ctypes.c_void_p]
sorts.bubbleSortStep.restype = ctypes.c_bool
sorts.bubbleSortFree.argtypes = [ctypes.c_void_p]
sorts.bubbleSortFree.restype = None

class BubbleSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.bubbleSortInit(self.data, self.size)

    def step(self):
        return sorts.bubbleSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def get_highlight_i(self):
        return sorts.comparisonSortGetHighlightI(self.state)
    def get_highlight_j(self):
        return sorts.comparisonSortGetHighlightJ(self.state)
    def get_highlight_write(self):
        return -1
    
    def get_sound_data(self):
        return self.data[sorts.comparisonSortGetHighlightJ(self.state)]
    
    def cleanup(self):
        sorts.bubbleSortFree(self.state)


### Insertion Sort
sorts.insertionSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.insertionSortInit.restype = ctypes.c_void_p
sorts.insertionSortStep.argtypes = [ctypes.c_void_p]
sorts.insertionSortStep.restype = ctypes.c_bool
sorts.insertionSortFree.argtypes = [ctypes.c_void_p]
sorts.insertionSortFree.restype = None

class InsertionSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.insertionSortInit(self.data, self.size)

    def step(self):
        return sorts.insertionSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def get_highlight_i(self):
        return sorts.comparisonSortGetHighlightI(self.state)
    def get_highlight_j(self):
        return sorts.comparisonSortGetHighlightJ(self.state)
    def get_highlight_write(self):
        return -1
    
    def get_sound_data(self):
        return self.data[sorts.comparisonSortGetHighlightJ(self.state)]

    def cleanup(self):
        sorts.insertionSortFree(self.state)

### Selection Sort
sorts.selectionSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.selectionSortInit.restype = ctypes.c_void_p
sorts.selectionSortStep.argtypes = [ctypes.c_void_p]
sorts.selectionSortStep.restype = ctypes.c_bool
sorts.selectionSortFree.argtypes = [ctypes.c_void_p]
sorts.selectionSortFree.restype = None

class SelectionSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.selectionSortInit(self.data, self.size)

    def step(self):
        return sorts.selectionSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def get_highlight_i(self):
        return sorts.comparisonSortGetHighlightI(self.state)
    def get_highlight_j(self):
        return sorts.comparisonSortGetHighlightJ(self.state)
    def get_highlight_write(self):
        return sorts.comparisonSortGetHighlightWrite(self.state)
    
    def get_sound_data(self):
        return self.data[sorts.comparisonSortGetHighlightWrite(self.state)]
    
    def cleanup(self):
        sorts.selectionSortFree(self.state)

## Quick Sort
sorts.quickSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.quickSortInit.restype = ctypes.c_void_p
sorts.quickSortStep.argtypes = [ctypes.c_void_p]
sorts.quickSortStep.restype = ctypes.c_bool
sorts.quickSortGetHighlightI.argtypes = [ctypes.c_void_p]
sorts.quickSortGetHighlightI.restype = ctypes.c_int
sorts.quickSortGetHighlightJ.argtypes = [ctypes.c_void_p]
sorts.quickSortGetHighlightJ.restype = ctypes.c_int
sorts.quickSortGetHighlightWrite.argtypes = [ctypes.c_void_p]
sorts.quickSortGetHighlightWrite.restype = ctypes.c_int
sorts.quickSortFree.argtypes = [ctypes.c_void_p]
sorts.quickSortFree.restype = None

class QuickSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.quickSortInit(self.data, self.size)

    def step(self):
        return sorts.quickSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def get_highlight_i(self):
        return sorts.quickSortGetHighlightI(self.state)
    def get_highlight_j(self):
        return sorts.quickSortGetHighlightJ(self.state)
    def get_highlight_write(self):
        return sorts.quickSortGetHighlightWrite(self.state)
    
    def get_sound_data(self):
        return self.data[sorts.quickSortGetHighlightI(self.state)]
    
    def cleanup(self):
        sorts.quickSortFree(self.state)

## Merge Sort
sorts.mergeSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.mergeSortInit.restype = ctypes.c_void_p
sorts.mergeSortStep.argtypes = [ctypes.c_void_p]
sorts.mergeSortStep.restype = ctypes.c_bool
sorts.mergeSortGetHighlightI.argtypes = [ctypes.c_void_p]
sorts.mergeSortGetHighlightI.restype = ctypes.c_int
sorts.mergeSortGetHighlightJ.argtypes = [ctypes.c_void_p]
sorts.mergeSortGetHighlightJ.restype = ctypes.c_int
sorts.mergeSortGetHighlightWrite.argtypes = [ctypes.c_void_p]
sorts.mergeSortGetHighlightWrite.restype = ctypes.c_int
sorts.mergeSortFree.argtypes = [ctypes.c_void_p]
sorts.mergeSortFree.restype = None

class MergeSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.mergeSortInit(self.data, self.size)

    def step(self):
        return sorts.mergeSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def get_highlight_i(self):
        return sorts.mergeSortGetHighlightI(self.state)
    def get_highlight_j(self):
        return sorts.mergeSortGetHighlightJ(self.state)
    def get_highlight_write(self):
        return sorts.mergeSortGetHighlightWrite(self.state)
    
    def get_sound_data(self):
        val = self.get_highlight_i()
        if (val < 0 or val > self.size):
            return 0
        return self.data[val]
    
    def cleanup(self):
        sorts.mergeSortFree(self.state)

## Radix Sort
sorts.radixSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.radixSortInit.restype = ctypes.c_void_p
sorts.radixSortStep.argtypes = [ctypes.c_void_p]
sorts.radixSortStep.restype = ctypes.c_bool
sorts.radixSortGetHighlightWrite.argtypes = [ctypes.c_void_p]
sorts.radixSortGetHighlightWrite.restype = ctypes.c_int
sorts.radixSortFree.argtypes = [ctypes.c_void_p]
sorts.radixSortFree.restype = None

class RadixSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.radixSortInit(self.data, self.size)

    def step(self):
        return sorts.radixSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def get_highlight_i(self):
        return -1
    def get_highlight_j(self):
        return -1
    def get_highlight_write(self):
        return sorts.radixSortGetHighlightWrite(self.state)
    
    def get_sound_data(self):
        return self.data[sorts.radixSortGetHighlightWrite(self.state)]
    
    def cleanup(self):
        sorts.radixSortFree(self.state)

## Counting Sort
sorts.countingSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.countingSortInit.restype = ctypes.c_void_p
sorts.countingSortStep.argtypes = [ctypes.c_void_p]
sorts.countingSortStep.restype = ctypes.c_bool
sorts.countingSortGetHighlightWrite.argtypes = [ctypes.c_void_p]
sorts.countingSortGetHighlightWrite.restype = ctypes.c_int
sorts.countingSortFree.argtypes = [ctypes.c_void_p]
sorts.countingSortFree.restype = None

class CountingSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.countingSortInit(self.data, self.size)

    def step(self):
        return sorts.countingSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def get_highlight_i(self):
        return -1
    def get_highlight_j(self):
        return -1
    def get_highlight_write(self):
        return sorts.countingSortGetHighlightWrite(self.state)
    
    def get_sound_data(self):
        return self.data[sorts.countingSortGetHighlightWrite(self.state)]
    
    def cleanup(self):
        sorts.countingSortFree(self.state)




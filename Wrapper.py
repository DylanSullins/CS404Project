import ctypes
import numpy as np
import os

dll_path = os.path.join(os.path.dirname(__file__), "StepSorts.dll")
try:
    sorts = ctypes.CDLL(dll_path)
except OSError as e:
    print("DLL load failed:")
    print(f"Path: {dll_path}")
    print(f"Error: {e}")
    raise


# FUNCTION SIGNATURES
## Bubble Sort
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
    
    def cleanup(self):
        sorts.bubbleSortFree(self.state)


## Insertion Sort
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
    
    def cleanup(self):
        sorts.insertionSortFree(self.state)

## Selection Sort
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
    
    def cleanup(self):
        sorts.selectionSortFree(self.state)

## Quick Sort
sorts.quickSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.quickSortInit.restype = ctypes.c_void_p
sorts.quickSortStep.argtypes = [ctypes.c_void_p]
sorts.quickSortStep.restype = ctypes.c_bool
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
    
    def cleanup(self):
        sorts.quickSortFree(self.state)

## Merge Sort
sorts.mergeSortInit.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.mergeSortInit.restype = ctypes.c_void_p
sorts.mergeSortStep.argtypes = [ctypes.c_void_p]
sorts.mergeSortStep.restype = ctypes.c_bool
sorts.mergeSortFree.argtypes = [ctypes.c_void_p]
sorts.mergeSortFree.restype = None

class QuickSortWrapper:
    def __init__(self, array):
        self.size = len(array)
        self.data = (ctypes.c_int * self.size)(*array)
        self.state = sorts.mergeSortInit(self.data, self.size)

    def step(self):
        return sorts.mergeSortStep(self.state)
    
    def get_array(self):
        return list(self.data)
    
    def cleanup(self):
        sorts.mergeSortFree(self.state)
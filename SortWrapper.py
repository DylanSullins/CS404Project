import ctypes
import os

""" Python Wrapper for C++ Sorting Algorithms
Wraps C++ implemented sorting algorithms in python classes for use in Sort.py
"""

dll_path = os.path.join(os.path.dirname(__file__), "Sorts.dll")
try:
    sorts = ctypes.CDLL(dll_path)
except OSError as e:
    print("DLL load failed:")
    print(f"Path: {dll_path}")
    print(f"Error: {e}")
    raise

# Function Wrappers
sorts.isSortedRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.isSortedRaw.restype = ctypes.c_bool
def call_is_sorted(array):
    arr = (ctypes.c_int * len(array))(*array)
    return sorts.isSortedRaw(arr, len(array))
    

sorts.insertionSortRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.insertionSortRaw.restype = ctypes.c_void_p
def call_insertion_sort(array):
    arr = (ctypes.c_int * len(array))(*array)
    sorts.insertionSortRaw(arr, len(array))
    return list(arr)

sorts.selectionSortRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.selectionSortRaw.restype = ctypes.c_void_p
def call_selection_sort(array):
    arr = (ctypes.c_int * len(array))(*array)
    sorts.selectionSortRaw(arr, len(array))
    return list(arr)

sorts.bubbleSortRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.bubbleSortRaw.restype = ctypes.c_void_p
def call_bubble_sort(array):
    arr = (ctypes.c_int * len(array))(*array)
    sorts.bubbleSortRaw(arr, len(array))
    return list(arr)

sorts.quickSortRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.quickSortRaw.restype = ctypes.c_void_p
def call_quick_sort(array):
    arr = (ctypes.c_int * len(array))(*array)
    sorts.quickSortRaw(arr, len(array))
    return list(arr)

sorts.mergeSortRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.mergeSortRaw.restype = ctypes.c_void_p
def call_merge_sort(array):
    arr = (ctypes.c_int * len(array))(*array)
    sorts.mergeSortRaw(arr, len(array))
    return list(arr)

sorts.radixSortRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.radixSortRaw.restype = ctypes.c_void_p
def call_radix_sort(array):
    arr = (ctypes.c_int * len(array))(*array)
    sorts.radixSortRaw(arr, len(array))
    return list(arr)

sorts.countingSortRaw.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
sorts.countingSortRaw.restype = ctypes.c_void_p
def call_counting_sort(array):
    arr = (ctypes.c_int * len(array))(*array)
    sorts.countingSortRaw(arr, len(array))
    return list(arr)

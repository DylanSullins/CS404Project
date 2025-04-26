# CS404 Algorithms and Complexity
## A Comparison of Sorting Algorithms
### Author: Dylan Sullins
### Created April 2025

# Table of Contents
1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Methodology](#methodology)
4. [Content](#content)
5. [Examples](#examples)
6. [Conclusion](#conclusion)
7. [References](#references)


## Introduction

This project is a two-fold experimental comparison of sorting algorithms. The sorting algorithms were implemented in C++, compiled into a DLL, and wrapped in Python for testing. The algorithms were also implemented using state-based logic for visualization.

## Objectives

The objective of this project was to analyze the experimental runtime of various different sorting algorithms and compare the results with the theoretical time complexity of the algorithms. 

## Methodology

The sorting methods chosen were Insertion, Selection, Bubble, Quick, Merge, Radix (base 10), and Counting Sort. These were chosen to ensure a wide spectrum of algorithmic efficiency across the algorithms. 

Algorithms were originally adapted from algorithms found in the course materials created by Dr. Gharibi for UMKC's course CS404 Introduction to Algorithms and Complexity, Spring 2025, accessed through canvas.

The original prototype algorithms were written in C++, as it is the language with which the author has the most confidence and proficiency. 

Initially, the plan was to implement a visualizer using the SDL (Simple DirectMedia Layer) library, a simple graphics library for C++. Unfortunately, after fighting with dependencies and errors, the project's direction was changed. Instead, the algorithms remained implemented in C++, but were now wrapped in Python to allow rapid prototyping of a visualizer through Python's Pygame library, which utilizes the SDL library.

In order to properly visualize the sorts, the algorithms required refactoring into step by step methods that relied on and updated a State (implemented as a Python class) that held the array, and various data about the state of the sort.

Once this was complete, the original algorithms were also wrapped in Python. Python's time library was used to test experimental runtime, and the results were plotted using Python's matplotlib library.

In order to compare similar-growth algorithms, the sorts were split into two groups: Simple sorting algorithms and efficient sorting algorithms.

## Results

As was expected, the simple sorting algorithms grew much faster than the efficient ones as the number of items in the list increased. Experimentally, there is a very fine balance in finding datasets where the simple sorts can be realistically compared to the efficient sorts. If the dataset is too small, the efficient algorithms might finish faster than Python's time library can actually time.

However, it is clear from the experimental data that the efficient sorts far outpaced the simple sorts. So does that mean that efficient sorts are faster than the simple sorts? Well, no. But it does mean that, given the specific randomized dataset that was generated for each trial run, on the author's specific hardware, with the same parameters, that the efficient sorts complete the process in a shorter time.

In order to show definitively that the efficient sorts are faster than the simple sorts, one must examine each algorithm theoretically. 

### Theoretical Time Complexity

The theoretical time complexity of an algorithm describes its growth relative to input. Generally, the relevant input is *n* for the number of items in the container being sorted. However, as we will discuss, this is not always the only contributing factor.

* Insertion Sort
> Best Case: Ω(n) (when the list is already sorted)

> Average Case: θ(n<sup>2</sup>)

> Worst Case: O(n<sup>2</sup>)

* Selection Sort
> Best Case: Ω(n<sup>2</sup>)

> Average Case: θ(n<sup>2</sup>)

> Worst Case: O(n<sup>2</sup>)

* Bubble Sort:

> Best Case: Ω(n) (when the list is already sorted)

> Average Case: θ(n<sup>2</sup>)

> Worst Case: O(n<sup>2</sup>)

* Quick Sort

> Best Case: Ω(nlgn)

> Average Case: θ(nlgn)

> Worst Case: O(n<sup>2</sup>) if minimum or maximum is repeatedly chosen as the pivot point for partitioning

* Merge Sort

> Best Case: Ω(nlgn)

> Average Case: θ(nlgn)

> Worst Case: O(nlgn)

* Radix Sort

> Best Case: Ω(d*(n+b)) (where d is the number of digits in the maximum value and b is the selected base)

> Average Case: θ(d*(n+b))

> Worst Case: O(d*(n+b))

* Counting Sort

> Best Case: Ω(n + k) (where k is the range [max - min])

> Average Case: θ(n + k)

> Worst Case: O(n + k)

An important note about Counting Sort: Counting sort has a time complexity of O(n+k), but this typically reduces down to O(n). However, for some datasets, the range of the data grows faster than the number of inputs. For example, if you have ten items in a list and the items range from (0, 10000), the runtime of the algorithm is determined by k. 

## Examples

## Conclusion

Ultimately, the sorting algorithm chosen is largely dependent on the dataset. If one is working with a potentially large dataset, choosing an algorithm from the efficient sorts can greatly increase efficiency. However, if one is working with a dataset that will remain relatively small, the ease of implementation of the simple sorts can reduce manpower cost. 

In addition to this, though it was not a main focus of the project, more efficient sorts can often come with increased space complexity. For example, the simple sorts have a worst case auxiliary space complexity equivalent to O(1), or constant. This means that they use zero additional space and perform their operations directly on the container being sorted. On the other hand, quick sort and merge sort have worst case auxiliary space complexity equivalent to O(n) due to recursive calls. If one is working in an environment where space in memory is limited, a simple sort may be the better option.

## References

UMKC COMP_SCI 404 Introduction to Algorithms and Complexity, Dr. Gharibi, accessed on Canvas.

Time Complexities of All Sorting Algorithms, Geeks for Geeks, accessed via https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/ 
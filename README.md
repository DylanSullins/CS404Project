# CS404Project
CS404 Sorting Algorithms Comparison Project

## Requirements
C++, GCC compiler or other compiler 

Python, Pygame, numpy, matplotlib

## Installation Instructions

* First, clone the git repository using the command
> git clone https://github.com/DylanSullins/CS404Project.git
* Next, change your directory to the repository directory using the command
> cd CS404Project
* Next, compile the C++ code for the sorting algorithms using the command
>g++ -shared -static -static-libgcc -static-libstdc++ -o Sorts.dll src/Sorts.cpp
* Next, compile the C++ code for the state-based, step-by-step sorting algorithms using the command
> g++ -shared -static -static-libgcc -static-libstdc++ -o StepSorts.dll src/StepSorts.cpp
* To run the runtime calculator, run the Python code with the command
> py ./Sort.py [n] [m] [i] [p]
* Where 
    > n = integer number of items

    > m = integer maximum possible number to generate

    > i = integer number of iterations to run

    > p = string mode parameter (-A for all sorts, -C for simple sorts, -E for efficient sorts)
* To run the visualizer, run the Python code with the command 
> py ./Visualizer.py 
    
* Note:
    * The default settings in the Visualizer.py (located at the top) can be changed to match display size, and the number of items in the list is determined by the WIDTH divided by the BAR_WIDTH. 
    
    * For best results, the WIDTH and HEIGHT should be set to your monitor's WIDTH and HEIGHT, and the number of items should be controlled by adjusting the BAR_WIDTH constant.

    * Press the ESC key to start, and again to skip the current sorting algorithm

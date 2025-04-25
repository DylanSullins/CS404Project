import matplotlib.pyplot as plt
import random
import sys
import time

import SortWrapper

def main():
    if (len(sys.argv) != 5):
        print(f"Invalid Syntax: Sorts.py [numItems] [maxNum] [repeats] [-A/-C/-E]")
        return -1
    try:
        run_parameter = sys.argv[4]
        if run_parameter not in ("-A", "-C", "-E"):
            run_parameter = "-A"
        repeats = int(sys.argv[3])
        length = int(sys.argv[2])
        max_number = int(sys.argv[1])
    except ValueError as e:
        print(f"TypeError: {e}")
        return -1
    except IndexError as e:
        print(f"IndexError: {e}")
        return -1
    insertionTimes = []
    selectionTimes = []
    bubbleTimes = []
    quickTimes = []
    mergeTimes = []
    radixTimes = []
    countingTimes = []

    for i in range(repeats):
        print(f"Run Number {i + 1}:")
        data = [random.randint(1, length) for _ in range(max_number)]
        print(f"\tRandom Data Generated")
        print(f"\t... Copying  Data ... ")
        if run_parameter == "-C" or run_parameter == "-A":
            insertionData = data[:]
            selectionData = data[:]
            bubbleData = data[:]
        if run_parameter == "-E" or run_parameter == "-A":
            quickData = data[:]
            mergeData = data[:]
            radixData = data[:]
            countingData = data[:]

        print(f"\tData Copied")
        print(f"\tBeginning Sorts . . . ")
        if run_parameter == "-C" or run_parameter == "-A":
            print(f"\tINSERTION SORT")
            t = time.process_time()
            insertionData = SortWrapper.call_insertion_sort(insertionData)
            elapsed = time.process_time() - t
            insertionTimes.append(elapsed * 10**6)
            if not SortWrapper.call_is_sorted(insertionData):
                print(f"\t\tWARNING: INSERTION SORT FAILED")
            else:
                print(f"\t\tElapsed Time : {elapsed * 10**6} microseconds")
            
            print(f"\tSELECTION SORT")
            t = time.process_time()
            selectionData = SortWrapper.call_selection_sort(selectionData)
            elapsed = time.process_time() - t
            selectionTimes.append(elapsed * 10**6)
            if not SortWrapper.call_is_sorted(selectionData):
                print(f"\t\tWARNING: SELECTION SORT FAILED")
            else:
                print(f"\t\tElapsed Time : {elapsed * 10**6} microseconds")
            
            print(f"\tBUBBLE SORT")    
            t = time.process_time()
            bubbleData = SortWrapper.call_bubble_sort(bubbleData)
            elapsed = time.process_time() - t
            bubbleTimes.append(elapsed * 10**6)
            if not SortWrapper.call_is_sorted(bubbleData):
                print(f"\t\tWARNING: BUBBLE SORT FAILED")
            else:
                print(f"\t\tElapsed Time : {elapsed * 10**6} microseconds")
        if run_parameter == "-E" or run_parameter == "-A":
            print(f"\tQUICK SORT")    
            t = time.process_time()
            quickData = SortWrapper.call_quick_sort(quickData)
            elapsed = time.process_time() - t
            quickTimes.append(elapsed * 10**6)
            if not SortWrapper.call_is_sorted(quickData):
                print(f"\t\tWARNING: QUICK SORT FAILED")
            else:
                print(f"\t\tElapsed Time : {elapsed * 10**6} microseconds")
            
            print(f"\tMERGE SORT")    
            t = time.process_time()
            mergeData = SortWrapper.call_merge_sort(mergeData)
            elapsed = time.process_time() - t
            mergeTimes.append(elapsed * 10**6)
            if not SortWrapper.call_is_sorted(mergeData):
                print(f"\t\tWARNING: MERGE SORT FAILED")
            else:
                print(f"\t\tElapsed Time : {elapsed * 10**6} microseconds")
            
            print(f"\tRADIX SORT")    
            t = time.process_time()
            radixData = SortWrapper.call_radix_sort(radixData)
            elapsed = time.process_time() - t
            radixTimes.append(elapsed * 10**6)
            if not SortWrapper.call_is_sorted(radixData):
                print(f"\t\tWARNING: RADIX SORT FAILED")
            else:
                print(f"\t\tElapsed Time : {elapsed * 10**6} microseconds")
            
            print(f"\tCOUNTING SORT")    
            t = time.process_time()
            countingData = SortWrapper.call_counting_sort(countingData)
            elapsed = time.process_time() - t
            countingTimes.append(elapsed * 10**6)
            if not SortWrapper.call_is_sorted(countingData):
                print(f"\t\tWARNING: COUNTING SORT FAILED")
            else:
                print(f"\t\tElapsed Time : {elapsed * 10**6} microseconds")

    if run_parameter == "-C" or run_parameter == "-A":    
        comparison_averages = {
            "Insertion" : sum(insertionTimes) / len(insertionTimes),
            "Selection" : sum(selectionTimes) / len(selectionTimes),
            "Bubble" : sum(bubbleTimes) / len(bubbleTimes)
        }
    if run_parameter == "-E" or run_parameter == "-A":
        efficient_averages = {
            "Quick" : sum(quickTimes) / len(quickTimes),
            "Merge" : sum(mergeTimes) / len(mergeTimes),
            "Radix" : sum(radixTimes) / len(radixTimes),
            "Counting" : sum(countingTimes) / len(countingTimes)
        }

    if run_parameter == "-C" or run_parameter == "-A":
        plt.bar(comparison_averages.keys(), comparison_averages.values())
        plt.title(f"Comparison Sorting Algorithms - Average Experimental Runtime")
        plt.xlabel("Algorithm")
        plt.ylabel("Experimental Runtime in microseconds")
        plt.savefig(f"matplot_output/average_graph_comp_sorts_{length}_{max_number}_{repeats}_{run_parameter}.jpg")
        plt.show()

    if run_parameter == "-E" or run_parameter == "-A":
        plt.bar(efficient_averages.keys(), efficient_averages.values())
        plt.title(f"Efficient Sorting Algorithms - Average Experimental Runtime")
        plt.xlabel("Algorithm")
        plt.ylabel("Experimental Runtime in microseconds")
        plt.savefig(f"matplot_output/average_graph_eff_sorts_{length}_{max_number}_{repeats}_{run_parameter}.jpg")
        plt.show()



if __name__ == "__main__":
    main()
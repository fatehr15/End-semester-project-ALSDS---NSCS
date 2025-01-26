#include <stdio.h>
#include <stdbool.h>
#include "ArrayOperations.h"

void print_array(int arr[], int size) {
    printf("[");
    for(int i=0; i<size; i++) {
        printf("%d%s", arr[i], (i < size-1) ? ", " : "");
    }
    printf("]\n");
}

void test_basic_operations() {
    printf("\n=== Testing Basic Array Operations ===\n");
    int arr[5] = {5, 2, 8, 1, 9};
    int size = 5;
    
    // Initialize and print
    initializeArray(arr, size, 0);
    printf("Initialized array: ");
    printArray(arr, size);
    
    // Restore values
    int test_arr[] = {5, 2, 8, 1, 9};
    memcpy(arr, test_arr, sizeof(test_arr));
    
    printf("Original array: ");
    print_array(arr, size);
    
    printf("Max value: %d (Expected 9)\n", findMax(arr, size));
    printf("Min value: %d (Expected 1)\n", findMin(arr, size));
    printf("Sum: %d (Expected 25)\n", sumArray(arr, size));
    printf("Average: %.2f (Expected 6.25)\n", averageArray(arr, size));
    printf("Is sorted? %s (Expected false)\n", isSorted(arr, size) ? "true" : "false");
}

void test_intermediate_operations() {
    printf("\n=== Testing Intermediate Operations ===\n");
    int arr[] = {5, 2, 8, 1, 9, 2, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    // Reverse array
    reverseArray(arr, size);
    printf("Reversed array: ");
    print_array(arr, size);  // Expected [9, 1, 8, 2, 5, 2, 5]
    
    // Even/odd count
    int even, odd;
    countEvenOdd(arr, size, &even, &odd);
    printf("Even: %d, Odd: %d (Expected Even: 2, Odd: 5)\n", even, odd);
    
    // Second largest
    printf("Second largest: %d (Expected 8)\n", secondLargest(arr, size));
    
    // Remove duplicates
    int new_size = removeDuplicates(arr, size);
    printf("Array after removing duplicates: ");
    print_array(arr, new_size);  // Expected [9, 1, 8, 2, 5]
}

void test_search_operations() {
    printf("\n=== Testing Search Operations ===\n");
    int arr[] = {1, 3, 5, 7, 9};
    int size = 5;
    
    printf("Linear search for 5: index %d (Expected 2)\n", 
          linearSearch(arr, size, 5));
    printf("Binary search for 7: index %d (Expected 3)\n", 
          binarySearch(arr, size, 7));
    
    // Test shifts
    leftShift(arr, size, 2);
    printf("After 2 left shifts: ");
    print_array(arr, size);  // Expected [5, 7, 9, 1, 3]
}

void test_sorting_algorithms() {
    printf("\n=== Testing Sorting Algorithms ===\n");
    int arr[] = {5, 2, 8, 1, 9};
    int size = 5;
    
    // Bubble sort
    bubbleSort(arr, size);
    printf("Bubble sorted: ");
    print_array(arr, size);  // Expected [1, 2, 5, 8, 9]
    
    // Selection sort
    int arr2[] = {5, 2, 8, 1, 9};
    selectionSort(arr2, size);
    printf("Selection sorted: ");
    print_array(arr2, size);  // Expected [1, 2, 5, 8, 9]
    
    // Insertion sort
    int arr3[] = {5, 2, 8, 1, 9};
    insertionSort(arr3, size);
    printf("Insertion sorted: ");
    print_array(arr3, size);  // Expected [1, 2, 5, 8, 9]
    
    // Merge sort
    int arr4[] = {5, 2, 8, 1, 9};
    mergeSort(arr4, 0, size-1);
    printf("Merge sorted: ");
    print_array(arr4, size);  // Expected [1, 2, 5, 8, 9]
}

void test_advanced_operations() {
    printf("\n=== Testing Advanced Operations ===\n");
    int arr[] = {1, 3, 4, 2, 5};
    int size = 5;
    
    // Missing number
    printf("Missing number: %d (Expected 5)\n", 
          FindMissingNumber(arr, size));  // Note: This test needs adjustment
    
    // Pairs with sum
    printf("Pairs with sum 5:\n");
    FindPairsWithSum(arr, size, 5);  // Expected (1,4) and (2,3)
    
    // Majority element
    int maj_arr[] = {2, 2, 3, 2, 4, 2, 2};
    printf("Majority element: %d (Expected 2)\n", 
          findMajorityElement(maj_arr, 7));
    
    // Longest increasing subsequence
    int seq_arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("LIS length: %d (Expected 4)\n", 
          longestIncreasingSubsequence(seq_arr, 8));
}

int main() {
    printf("=== Starting Array Operations Test Suite ===\n");
    
    test_basic_operations();
    test_intermediate_operations();
    test_search_operations();
    test_sorting_algorithms();
    test_advanced_operations();
    
    printf("\n=== All Array Tests Completed ===\n");
    return 0;
}
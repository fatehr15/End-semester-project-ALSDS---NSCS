#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <stdbool.h>
#include <stdio.h>

/* Basic Array Operations */
void initializeArray(int arr[], int size, int value);
void printArray(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
int sumArray(int arr[], int size);
double averageArray(int arr[], int size);
bool isSorted(int arr[], int size);

/* Intermediate Array Operations */
void reverseArray(int arr[], int size);
void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount);
int secondLargest(int arr[], int size);
void elementFrequency(int arr[], int size);
int removeDuplicates(int arr[], int size);
int binarySearch(int arr[], int size, int target);
int linearSearch(int arr[], int size, int target);
void leftShift(int arr[], int size, int rotations);
void rightShift(int arr[], int size, int rotations);
void swapArr(int* a, int* b);

/* Sorting Algorithms */
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);

/* Advanced Array Operations */
int FindMissingNumber(int arr[], int size);
void FindPairsWithSum(int arr[], int size, int sum);
void findSubArrayWithSum(int arr[], int size, int sum);
void rearrangeAlternatePositiveNegative(int arr[], int size);
int findMajorityElement(int arr[], int size);
int longestIncreasingSubsequence(int arr[], int size);

#endif 
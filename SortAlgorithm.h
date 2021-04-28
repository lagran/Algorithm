#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H
#include <iostream>

#define MAX_VALUE 100000
void BubbleSort(int arr[], int size);

void QuickSort(int arr[], int start, int end);

void InsertSort(int arr[], int size);

void ShellSort(int arr[], int size);

void SelectionSort(int arr[], int size);

void HeapSort(int arr[], int size);

void MergeSort(int arr[], int start, int end);

void CountingSort(int arr[], int size, int max_value);

void BucketSort(int arr[], int size, int bucket_size);

void RadixSort(int arr[], int size);
#endif

//#include "SortAlgorithm.cpp"

#ifndef SORTS_H
    #define SORTS_H
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

    void bubble_sort(int* array, int n, long long int* counts);
    void selection_sort(int* array, int n, long long int* counts);
    void insertion_sort(int* array, int n, long long int* counts);
    void shellSort(int* arr, int n, long long int* counts);
    void quick_sort(int* array, int left, int right, long long int* counts);
    void heap_sort(int* array, int size, long long int* counts);
    void mergeSort(int v[], int inicio, int fim, long long int *counts);
    void countingSort(int v[], int size, long long int *counts);
    void radix_sort(int v[], int n, long long int *counts);
#endif

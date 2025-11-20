#ifndef SORTS_H
    #define SORTS_H
    #include <stdlib.h>

    void bubble_sort(int* array, int n, int* counts);
    void selection_sort(int* array, int n, int* counts);
    void shellSort(int* arr, int n, int* counts);
    void quick_sort(int* array, int left, int right, int* counts);
    void heap_sort(int* array, int size, int* counts);
    void merge(int v[], int esq, int meio, int dir);
    void countingSort(int v[], int size);
#endif
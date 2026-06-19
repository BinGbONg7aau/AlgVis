#ifndef MERGESORT_H
#define MERGESORT_H

void mergeSort();
static void _mergeSort(int *array, int length, int r);
static void _merge(int *array, int length, int m, int r);
static void printMergeArray(int *array, int l, int r);

#endif

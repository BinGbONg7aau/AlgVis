#include "mergeSort.h"
#include "../helperFunctions.h"

static void _mergeSort(int *array, int l, int r, int depth);
static void _merge(int *array, int l, int m, int r, int depth);
static void printMergeArray(int *array, int l, int r);
static void printIndent(int depth);

void mergeSort() {
    int length = -1;
    int *array;

    printf("MERGE SORT\n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array:\n");
    printArray(array, length);
    printf("\n");

    _mergeSort(array, 0, length - 1, 0);

    printf("Sorted array:\n");
    printArray(array, length);

    free(array);
}

static void _mergeSort(int *array, int l, int r, int depth) {

    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    printIndent(depth);
    printf("Sorting range [%d..%d]\n", l, r);

    printIndent(depth);
    printf("Split at index %d\n", m);

    printIndent(depth);
    printf("Left  (%d..%d): ", l, m);
    printMergeArray(array, l, m);

    printIndent(depth);
    printf("Right (%d..%d): ", m + 1, r);
    printMergeArray(array, m + 1, r);

    printf("\n");

    _mergeSort(array, l, m, depth + 1);
    _mergeSort(array, m + 1, r, depth + 1);

    _merge(array, l, m, r, depth);
}

static void _merge(int *array, int l, int m, int r, int depth) {

    printIndent(depth);
    printf("----------------------------------------\n");

    printIndent(depth);
    printf("Merge\n");

    printIndent(depth);
    printf("Left : ");
    printMergeArray(array, l, m);

    printIndent(depth);
    printf("Right: ");
    printMergeArray(array, m + 1, r);

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = array[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    while (i < n1)
        array[k++] = L[i++];

    while (j < n2)
        array[k++] = R[j++];

    printIndent(depth);
    printf("Result: ");
    printMergeArray(array, l, r);

    printIndent(depth);
    printf("----------------------------------------\n\n");
}

static void printMergeArray(int *array, int l, int r) {

    printf("[");

    for (int i = l; i <= r; i++) {

        if (i > l)
            printf(", ");

        printf("%d", array[i]);
    }

    printf("]\n");
}

static void printIndent(int depth) {

    for (int i = 0; i < depth; i++)
        printf("    ");
}
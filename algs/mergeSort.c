#include "mergeSort.h"
#include "../helperFunctions.h"

void mergeSort() {
    int length = -1;
    int *array;

    printf("MERGE SORT\n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array: \n");
    printArray(array, length);

    _mergeSort(array, 0, length-1);
    printArray(array, length);

    free(array);
}

static void _mergeSort(int *array, int l, int r) {
    
    if (l < r) {
        int m = l + (r - l) / 2;
        printf("m: %d\n", m);
        printf("Left: ");
        printMergeArray(array, l, m);

        printf("Right: ");
        printMergeArray(array, m+1, r);

        // Sort first and second halves
        _mergeSort(array, l, m);
        _mergeSort(array, m + 1, r);

        _merge(array, l, m, r);
    }
}

static void _merge(int *array, int l, int m, int r) {
    
    printf("\nMerging the following arrays now:\n");
    printMergeArray(array, l, m);
    printMergeArray(array, m+1, r);

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    // Merge the temp arrays back into array[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    printf("Merge finished with result\n");
    printMergeArray(array, l, r);
    printf("\n");
}

static void printMergeArray(int *array, int l, int r) {
    printf("[");
    for (; l < r; l++) {
        printf("%d, ", array[l]);
    }
    printf("%d]\n", array[r]);
}

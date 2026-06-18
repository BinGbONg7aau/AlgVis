#include "insertionSort.h"
#include "../helperFunctions.h"

void insertionSort() {
    int length = -1;
    int *array;

    printf("INSERTION SORT\n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array: \n");
    printArray(array, length);

    _insertionSort(array, length);
}

static void _insertionSort(int *array, int length) {
    for (int i = 1; i < length; ++i) {
        int key = array[i];
        int j = i - 1;

        printf("Insertion Step %d: \t key: %d\n", i, key);
        
        /* Move elements of array[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && array[j] > key) {
            printInsertionArray(array, length, key, j);
            printf(" -- Index j: %d, comparing array[j]: %d with key: %d, moving key down\n", j, array[j], key);
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
        printInsertionArray(array, length, key, j);
        printf(" -- Index j: %d, inserting key: %d on index j+1: %d \n", j, key, j+1);
        printf("\n");
    }
}

void printInsertionArray(int *array, int length, int key, int j) {
    printf("[");
    for (int i = 0; i < length-1; i++) {
        if (array[i] == key) {
            printf("_%d_, ", array[i]);
        } else if (i == j) {
            printf(">%d<, ", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }

    array[length-1]==key ? printf("_%d_]", array[length-1]) : printf("%d]", array[length-1]);
}
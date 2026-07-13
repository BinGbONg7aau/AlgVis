#include "insertionSort.h"
#include "../helperFunctions.h"

static void _insertionSort(int *array, int length);
static void printInsertionArray(int *array, int length, int insertedIndex, int j);

void insertionSort() {
    int length = -1;
    int *array;

    printf("INSERTION SORT\n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array:\n");
    printArray(array, length);
    printf("\n");

    _insertionSort(array, length);

    printf("Sorted array:\n");
    printArray(array, length);

    free(array);
}

static void _insertionSort(int *array, int length) {

    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;

        printf("=========================================\n");
        printf("Iteration %d\n", i);
        printf("Key = %d\n\n", key);

        while (j >= 0 && array[j] > key) {

            array[j + 1] = array[j];

            printInsertionArray(array, length, NO_INDEX, j);
            printf("Shift %d one position to the right because %d < %d\n\n",
                array[j], key, array[j]);

            j--;
        }

        array[j + 1] = key;

        printInsertionArray(array, length, j + 1, NO_INDEX);
        printf("Insert key %d at index %d\n\n", key, j + 1);
    }
}

static void printInsertionArray(int *array,
                                int length,
                                int insertedIndex,
                                int j)
{
    printf("Index:");

    for (int i = 0; i < length; i++) {
        printf("%5d", i);
    }

    printf("\nArray:");

    for (int i = 0; i < length; i++) {
        if (i == insertedIndex){
            printf("  _%2d", array[i]);
        } else if (i == j){
            printf("  >%2d", array[i]);
        } else
            printf("%5d", array[i]);
    }
    printf("\n");
}
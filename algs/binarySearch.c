#include "binarySearch.h"
#include "../helperFunctions.h"

static int _binarySearch(int *array, int length);

void binarySearch(){
    int length = -1;
    int *array;
    
    printf("BINARY SEARCH \n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array: \n");
    printArray(array, length);

    printf("Sorting Array for Binary Search...\n");
    qsort(array, length, sizeof(int), comp);

    printf("Sorted array: \n");
    printArray(array, length);

    _binarySearch(array, length);

    free(array);
}

static int _binarySearch(int *array, int length){
    int low = 0;
    int high = length-1;
    int value;
    int i = 0;

    printf("Input value to search for: \n");
    scanf(" %3d", &value);
    printf("\n");

    while (low <= high) {
        int mid = low + (high - low) / 2;
        printf("Step %d | indeces: low=%d mid=%d high=%d\n", i + 1, low, mid, high);
        if (array[mid] == value) {
            printf("Compare %d with %d -> FOUND\n", value, array[mid]);
            printBinArray(array, length, low, mid, high);
            printf("Value found at index %d\n", mid);
            return mid;
        }

        printf("Compare %d with %d -> go %s\n",
            value,
            array[mid],
            value > array[mid] ? "right" : "left");

        //printf("Search step %d: \t low: %d, mid: %d, high: %d\n", i+1, low, mid, high);
        printBinArray(array, length, low, mid, high);
        if (array[mid] == value) {
            printf("Value found, returning index: %d\n", mid);
            return mid;
        }
        
        if (array[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        i++;
    }

    printf("Value not found, returning -1\n");
    return -1;
}

void printBinArray(int *array, int length, int low, int mid, int high)
{
    printf("Index: ");

    for (int i = 0; i < length; i++)
        printf("%4d", i);

    printf("\nArray: ");

    for (int i = 0; i < length; i++)
        printf("%4d", array[i]);

    printf("\n      ");

    for (int i = 0; i < length; i++) {
        if (i == low && i == mid && i == high)
            printf("%4s", "LMH");
        else if (i == low && i == mid)
            printf("%4s", "LM");
        else if (i == mid && i == high)
            printf("%4s", "MH");
        else if (i == low)
            printf("%4s", "L");
        else if (i == mid)
            printf("%4s", "M");
        else if (i == high)
            printf("%4s", "H");
        else
            printf("%4s", "");
    }

    printf("\n\n");
}

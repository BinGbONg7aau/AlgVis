#include "binarySearch.h"
#include "../helperFunctions.h"

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

    while (low <= high) {
        int mid = low + (high - low) / 2;
        printf("Search step %d: \t low: %d, mid: %d, high: %d\n", i+1, low, mid, high);
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

void printBinArray(int *array, int length, int low, int mid, int high) {
    low == 0 ? printf("[->%d<-, ", array[0])  : printf("[%d, ", array[0]);

    for (int i = 1; i < length - 1; i++) {
        if (i == low || i == mid || i == high) {
            printf("->%d<-, ", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    high == length -1 ? printf("->%d<-]\n\n", array[length-1]) : printf("%d]\n\n", array[length-1]);;
}

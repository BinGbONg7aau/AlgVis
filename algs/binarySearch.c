#include "binarySearch.h"
#include "../helperFunctions.h"

void binarySearch(){
    int length = -1;
    int *array;
    
    printf("BINARY SEARCH \n");

    promptArrayLength(&length);
    array = generateArray(length);

    //TODO sort array
    populateArrayRandomWithoutDuplicates(array, length);

    printf("Generated array: \n[");
    for (int i = 0; i < length - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[length-1]);

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
        printf("Search step %d: \t low: %d, high: %d, mid: %d\n", i, low, high, mid);
        if (array[mid] == value) {
            printf("Value found, returning index: %d\n", mid);
            return mid;
        }
        
        if (array[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
        
        i++;
    }

    printf("Value not found, returning -1\n");
    return -1;
}

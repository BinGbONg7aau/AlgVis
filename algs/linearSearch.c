#include "linearSearch.h"
#include "../helperFunctions.h"

static int _linearSearch(int *array, int length);
static void printLinArray(int *array, int length, int index);

void linearSearch(){
    int length = -1;
    int *array;
    
    printf("LINEAR SEARCH \n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array: \n");
    printArray(array, length);

    _linearSearch(array, length);

    free(array);
}

static int _linearSearch(int *array, int length)  {
    int value;
    printf("Input value to search for: \n");
    scanf(" %3d", &value);
    printf("\n");

    for (int i = 0; i < length; i++) {    
        printf("Search step %d\n", i+1);
        printLinArray(array, length, i);

        if (value == array[i]) {
            printf("Value %d found, returning index %d\n", value, i);
            return i;
        }
    }

    printf("Value not found, returning -1\n");
    return -1;
}

static void printLinArray(int *array, int length, int index) {
    printf("Index:");

    for (int i = 0; i < length; i++) {
        printf("%5d", i);
    }

    printf("\nArray:");
    for (int i = 0; i < length; i++) {
        i == index ? printf("  >%2d", array[i]) : printf("%5d", array[i]);
    }

    printf("\n\n");
}

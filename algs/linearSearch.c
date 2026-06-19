#include "linearSearch.h"
#include "../helperFunctions.h"

void linearSearch(){
    int length = -1;
    int *array;
    
    printf("LINEAR SEARCH \n");

    promptArrayLength(&length);
    array = generateArray(length);
    promptArrayGen(length, array);

    printf("Generated array: \n");
    printArray(array, length);

    _linearSearch(array, length);

    free(array);
}

static int _linearSearch(int *array, int length)  {
    int value;
    printf("Input value to search for: \n");
    scanf(" %3d", &value);

    for (int i = 0; i < length; i++) {    
        printf("Search step %d:\tIndex %d and Value %d\n", i+1, i, array[i]);
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
    printf("[");
    for (int i = 0; i < length-1; i++) {
        i == index ? printf("->%d<-, ", array[i]) : printf("%d, ", array[i]);
    }
    index == length-1 ? printf("->%d<-]\n\n", array[length-1]) : printf("%d]\n\n", array[length-1]);
}

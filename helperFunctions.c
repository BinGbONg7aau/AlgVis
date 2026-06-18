#include "helperFunctions.h"

int* generateArray(int length) {
    return (int *)calloc(length, sizeof(int));
}

//Populate an array with random values without duplicates
void populateArrayRandom(int* array, int length) {
     int used[101] = {0};

    for (int i = 0; i < length; i++) {
        int r;

        do {
            r = rand() % 101;
        } while (used[r]);

        array[i] = r;
        used[r] = 1;
    }
}

void promptArrayLength(int *length) {
    printf("Input array length: \n");
    while (*length < 0 || *length > 100) {
        printf("length must be >= 0 and <= 100\n");
        scanf(" %3d", length);
    }
}

void promptArrayGen(int length, int* array) {
    char valueGenOpt;
    printf("Press m to generate manuel values, w to generate random values without duplicates\n");
    scanf(" %1c", &valueGenOpt);

    if (valueGenOpt == 'm') {
        //TODO   
    } else if(valueGenOpt == 'w') {
        populateArrayRandom(array, length);
    }
}

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void printArray(int *array, int length) {
    printf("[%d, ", array[0]);
    for (int i = 1; i < length - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n\n", array[length-1]);
}
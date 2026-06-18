#include "helperFunctions.h"


int* generateArray(int length) {
    return (int *)calloc(length, sizeof(int));
}

void populateArrayRandomWithDuplicates(int* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = rand() % (101);
    }
}

void populateArrayRandomWithoutDuplicates(int* array, int length) {
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
    printf("Press m to generate manuel values, d to generate random values with possible duplicates, w to generate random values without duplicates\n");
    scanf(" %1c", &valueGenOpt);

    if (valueGenOpt == 'm') {

    } else if(valueGenOpt == 'd') {
        populateArrayRandomWithDuplicates(array, length);    
    } else if(valueGenOpt == 'w') {
        populateArrayRandomWithoutDuplicates(array, length);
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
#include "quickSort.h"
#include "../helperFunctions.h"

static void _quickSort(int *array, int low, int high, int totalLength);
static void printQuickArray(int *array,
                            int totalLength,
                            int low,
                            int high,
                            int currentIndex,
                            int comparedIndex,
                            int pivotIndex);
static int _partition(int *array,
                      int low,
                      int high,
                      int totalLength);

void quickSort() {
    int length = -1;
    int *array;

    printf("QUICK SORT\n");

    promptArrayLength(&length);
    array = generateArray(length);
    populateArrayRandom(array, length);

    printf("Generated array:\n");
    printArray(array, length);
    printf("\n");

    _quickSort(array, 0, length - 1, length);

    printf("Sorted array:\n");
    printArray(array, length);

    free(array);
}

static void _quickSort(int *array, int low, int high, int totalLength) {
    if (low >= high) {
        printf("Base case: subarray [%d..%d] has one element or less.\n", low, high);
        return;
    }

    printf("\n=== Partitioning subarray [%d..%d] ===\n", low, high);
    int pivotIndex = _partition(array, low, high, totalLength);

    printf("Pivot placed at index %d\n", pivotIndex);
    printQuickArray(array, totalLength, low, high, pivotIndex, -1, pivotIndex);

    _quickSort(array, low, pivotIndex - 1, totalLength);
    _quickSort(array, pivotIndex + 1, high, totalLength);
}

static int _partition(int *array, int low, int high, int totalLength)
{
    int pivot = array[high];
    int i = low - 1;
    int step = 0;

    printf("Current range [%d..%d]\n", low, high);
    printf("Pivot value: %d\n", pivot);

    for (int j = low; j < high; j++) {
        step++;
        printf("Step %d: inspect index %d with value %d\n", step, j, array[j]);

        if (array[j] <= pivot) {
            i++;

            if (i != j) {
                printf("  -> Move %d to the left partition and swap with index %d\n", array[j], i);
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            } else {
                printf("  -> %d already belongs on the left side\n", array[j]);
            }
        } else {
            printf("  -> %d belongs on the right side\n", array[j]);
        }

        printQuickArray(array, totalLength, low, high, i, j, high);
        printf("\n");
    }

    printf("Final pivot swap: place %d at index %d\n", pivot, i + 1);
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    printQuickArray(array, totalLength, low, high, i + 1, -1, i + 1);
    printf("\n");

    return i + 1;
}

static void printQuickArray(int *array,
                            int totalLength,
                            int low,
                            int high,
                            int currentIndex,
                            int comparedIndex,
                            int pivotIndex)
{
    printf("State: ");

    for (int k = 0; k < totalLength; k++) {
        if (k == low) {
            printf("[");
        }

        if (k == currentIndex) {
            printf("*%d*", array[k]);
        } else if (k == comparedIndex) {
            printf("<%d>", array[k]);
        } else if (k == pivotIndex) {
            printf("{%d}", array[k]);
        } else {
            printf("%d", array[k]);
        }

        if (k < totalLength - 1) {
            printf(" ");
        }

        if (k == high) {
            printf("]");
        }
    }

    printf("\n");
}

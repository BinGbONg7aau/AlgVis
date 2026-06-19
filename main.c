#include "main.h"

int main(){
    printf("\nHello this is AlgVis, a algorithm visualisation tool\n");

    printf("Algorithm Options:\n");
    printf(" Type \"bs\" for Binary Search - O(log n)\n");
    printf(" Type \"ls\" for Linear Search - O(n)\n");
    printf(" Type \"is\" for Insertion Sort - O(n^2)\n");
    printf(" Type \"ms\" for Merge Sort - O(n log n)\n");
    //TODO
    //HASHMAP
    //BINARY TREE
    //BUBBLE SORT
    //QUICK SORT
    //HEAP SORT

    char input[5];

    scanf("%4s", input);

    if (!strcmp("bs", input)) {
        binarySearch();
    } else if (!strcmp("ls", input)){
        linearSearch();
    } else if (!strcmp("is", input)){
        insertionSort();
    } else if (!strcmp("ms", input)){
        mergeSort();
    } else {
        printf("Command not recognised, please try again\n");
    }

    return 0;
}

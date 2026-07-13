#include "main.h"

int main(){
    printf("\nHello this is AlgVis, a algorithm visualisation tool\n");

    printf("Algorithm Options:\n");
    printf(" Type \"bs\" for Binary Search - O(log n)\n");
    printf(" Type \"ls\" for Linear Search - O(n)\n");
    printf(" Type \"is\" for Insertion Sort - O(n^2)\n");
    printf(" Type \"ms\" for Merge Sort - O(n log n)\n");
    printf(" Type \"qs\" for Quick Sort O(n)\n");
    printf(" Type \"ll\" for Linked List Demo\n");
    printf(" Type \"hm\" for Hash Map Demo\n");
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
    } else if (!strcmp("ll", input)){
        linkedList();
    } else if (!strcmp("hm", input)){
        hashMap();
    } else if (!strcmp("qs", input)){
        quickSort();
    } else {
        printf("Command not recognised, please try again\n");
    }

    return 0;
}

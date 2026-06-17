#include "main.h"

int main(){
    printf("\nHello this is AlgVis, a algorithm visualisation tool\n");

    printf("Press bs for Binary Search\n");

    char inAlg[5];

    scanf("%4s", inAlg);

    if (!strcmp("bs", inAlg))
    {
        binarySearch();
    }

    return 0;
}

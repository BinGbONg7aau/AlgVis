#include "main.h"

int main(){
    printf("\nHello this is AlgVis, a algorithm visualisation tool\n");

    printf("Press bs for Binary Search, ls for Linear Search\n");

    char input[5];

    scanf("%4s", input);

    if (!strcmp("bs", input)) {
        binarySearch();
    } else if (!strcmp("ls", input)){
        linearSearch();
    }
    

    return 0;
}

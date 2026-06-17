#include "binarySearch.h"

void binarySearch(){
    int length = 0;
    char valueGenOpt;
    int *array;
    
    printf("BINARY SEARCH \n");
    printf("Input array length: \n");
    scanf(" %d", &length);

    array = (int *)calloc(length, sizeof(int));

    printf("Press m to generate manuel values, anything else to generate random values\n");
    scanf(" %c", &valueGenOpt);

    if (valueGenOpt == 'm')
    {

    } else {
        for (int i = 0; i < length; i++)
        {
            printf("%d", array[i]);
        }
        
    }
}

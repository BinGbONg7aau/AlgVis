#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateArray(int length);
void populateArrayRandomWithDuplicates(int* array, int length);
void populateArrayRandomWithoutDuplicates(int* array, int length);
void promptArrayLength(int *length);
void promptArrayGen(int length, int* array);
int comp(const void* a, const void* b);
void printArray(int *array, int length);

#endif

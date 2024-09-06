#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#include "arr.h"


void free_array(int *arr) 
{
    free(arr);
    arr = NULL;
}

 
int* new_random_intarray(int size) 
{
    int i;

    int* numbers = NULL;
    numbers = calloc(size, sizeof(int));

    if (numbers == NULL) 
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < size; i++) 
    {
        numbers[i] = i + 1;
    }

    randomize_iarr(numbers, size);

    return (numbers);
}


void remove_index(int index, int *arr, int size) 
{
    if (size <= 0 || index < 0 || index >= size)
        return;

    memmove(arr + index, arr + index + 1, (size - index) * sizeof(int));
}


void remove_random_index(int *arr, int size) 
{
    if (size <= 0)
        return;

    srand(time(NULL));

    int index_to_remove = 1 + rand() % (size - 1);
    int index_value = arr[index_to_remove];
    
    remove_index(index_to_remove, arr, size);

    printf("Index removed: %d;   value: %d\n", index_to_remove, index_value);
}


void randomize_iarr(int *arr, int size) 
{
    int i, j, t;

    srand(time(NULL));

    for (i = 0; i < size; i++) 
    {
        j = rand() % (size - i) + i;
        t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
    }
}
#include <stdio.h>
#include "print.h"


void print_array_with_message(char message[], int arr[], size_t size)
{
    printf("%s\n", message);

	print_array(arr, size);

    printf("\n");
}


void print_array(int arr[], int size)
{
	printf("[ %d", arr[0]);
	for (int i = 1; i < size; i++)
	{
		printf(", %d", arr[i]);
	}
	printf(" ]\n");
}
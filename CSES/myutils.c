#include <stdio.h>
#include "myutils.h"

void print_array_with_message(char* message, int* arr, size_t size) {
	printf("%s\n", message);
	for (size_t i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#include "arr.h"


int 
get_arr_size(int start, int max, int step)
{
	return (max - start) / step + 1;
}


void 
swap_indexes(int arr[], int this_index, int with_that_index)
{
	int temp;

	temp = arr[this_index];
	arr[this_index] = arr[with_that_index];
	arr[with_that_index] = temp;
}

//IMPLEMENT POP(n)
// refers to front of array

//IMPLEMENT PUSH(item)
// refers to front of array

//IMPLEMENT FIRST(n)

//IMPLEMENT LAST(n)

//IMPLEMENT SKIP(n)

//IMPLEMENT LEAVE(n)
// all but the last n items

//IMPLEMENT ADD(n items)
// refers to end of array
// generate new array + slots for add
// return reference to new array
// free old array
// new slots are empty \0

//IMPLEMENT REMOVE(index)
// generate 

//////// IARR stuff

// figure out some way to make generic call function that takes an enum that is
// a pointer to a function that does an action, so you can call like:
//		iarr.action(pop, 1);
//		iarr.action(push, int);
//		iarr.action(first, 4);
//		iarr.action(last, 3);
//		iarr.action(skip, 5);
//		iarr.action(leave, 10);
//		iarr.action(add, 5);
//		iarr.action(remove, 6);
// 
// see void * https://stackoverflow.com/questions/11626786/what-does-void-mean-and-how-to-use-it

iarr 
new_iarr(int size)
{
	iarr array;

	//int *arr = calloc(size, sizeof(int));
	array.length = size;
	array.array = calloc(size, sizeof(int));

	return array;
}


iarr 
new_sequential_iarr(int start, int max, int step)
{
	int i, j, size;

	size = get_arr_size(start, max, step);
	iarr arr = new_iarr(size);
	//numbers = calloc(size, sizeof(int));

	if (arr.array == NULL)
	{
		fprintf(stderr, "Memory allocation failed!\n");
		exit(1);
	}

	for (i = 0, j = start; i < arr.length; i++, j += step)
	{
		arr.array[i] = j;
	}

	return arr;
}


iarr 
new_random_iarr(int size)
{
	iarr arr = new_sequential_iarr(1, size, 1);
	randomize_iarr(arr);
	return arr;
}


void 
randomize_iarr(iarr arr)
{
	int i, j, t;

	srand(time(NULL));

	for (i = 0; i < arr.length; i++)
	{
		j = rand() % (arr.length - i) + i;
		swap_indexes(arr.array, j, i);
	}
}


void 
print_iarr(iarr arr)
{
	printf("\n\tsize: %zu\n", arr.length);
	printf("\tarray: [ %d", arr.array[0]);
	for (int i = 1; i < arr.length; i++) {
		printf(", %d", arr.array[i]);
	}
	printf(" ]\n\n");
}


void 
free_iarr(iarr arr)
{
	free(arr.array);
	arr.array = NULL;
}

////////IMPLEMENT FOR IARR


//void 
//remove_index(int index, int* arr, int size)
//{
//	// should update .length as well...
//	if (size <= 0 || index < 0 || index >= size)
//		return;
//
//	memmove(arr + index, arr + index + 1, (size - index) * sizeof(int));
//
//}


//void 
//remove_random_index(int* arr, int size)
//{
//	if (size <= 0)
//		return;
//
//	srand(time(NULL));
//
//	int index_to_remove = 1 + rand() % (size - 1);
//	int index_value = arr[index_to_remove];
//
//	remove_index(index_to_remove, arr, size);
//
//	printf("Index removed: %d;   value: %d\n", index_to_remove, index_value);
//}



/* regular integer array utility functions */

void 
free_array(int* arr)
{
	free(arr);
	arr = NULL;
}


int* 
new_sequential_int_array(int start, int max, int step)
{
	int i, j, size;

	size = get_arr_size(start, max, step);

	int* numbers = NULL;
	numbers = calloc(size, sizeof(int));

	if (numbers == NULL)
	{
		fprintf(stderr, "Memory allocation failed!\n");
		return 1;
	}

	for (i = 0, j = start; i < size; i++, j += step)
	{
		numbers[i] = j;
	}

	return numbers;
}


int* 
new_random_intarray(int size)
{
	int* numbers = new_sequential_int_array(1, size, 1);

	randomize_array(numbers, size);

	return (numbers);
}


void 
remove_index(int index, int* arr, int size)
{
	if (size <= 0 || index < 0 || index >= size)
		return;

	memmove(arr + index, arr + index + 1, (size - index) * sizeof(int));
}


void 
remove_random_index(int* arr, int size)
{
	if (size <= 0)
		return;

	srand(time(NULL));

	int index_to_remove = 1 + rand() % (size - 1);
	int index_value = arr[index_to_remove];

	remove_index(index_to_remove, arr, size);

	printf("Index removed: %d;   value: %d\n", index_to_remove, index_value);
}


void 
randomize_array(int* arr, int size)
{
	int i, j, t;

	srand(time(NULL));

	for (i = 0; i < size; i++)
	{
		j = rand() % (size - i) + i;
		swap_indexes(arr, j, i);
	}
}
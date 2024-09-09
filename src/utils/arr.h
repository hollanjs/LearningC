#pragma once


// CREATE
int* new_sequential_int_array(int start, int max, int step);
int* new_random_intarray(int size);


// READ
int get_arr_size(int start, int max, int step);


// UPDATE
void remove_index(int index, int *arr, int size);
void remove_random_index(int *arr, int size);
void randomize_array(int* arr, int size);
void swap_indexes(int arr[], int this_index, int with_that_index);


// DELETE
void free_array(int* arr);


// IARR stuff...
typedef struct integer_array {
	size_t length;
	int* array;
} iarr;

iarr new_iarr(int size);
iarr new_sequential_iarr(int start, int max, int step);
iarr new_random_iarr(int size);

void randomize_iarr(iarr arr);
void print_iarr(iarr arr);
void free_iarr(iarr arr);

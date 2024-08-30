#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void helloworld() {
	printf("Hello, World!\n");
}

#pragma region Utility
void print_array_with_message(char *message, int *arr, size_t size) {
	printf("%s\n", message);
	for (size_t i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}
#pragma endregion


#pragma region weird_algorithm
/*************************************************************************************************
 * 
 *		Consider an algorithm that takes as input a positive integer n. If n is even, 
 *		the algorithm divides it by two, and if n is odd, the algorithm multiplies it 
 *		by three and adds one. The algorithm repeats this, until n is one. 
 *
 *		For example, the sequence for n=3 is as follows:
 *		3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1 
 *
 *		Your task is to simulate the execution of the algorithm for a given value of n.
 *		
 *		Input
 *			The only input line contains an integer n.
 *		Output
 *			Print a line that contains all values of n during the algorithm.
 *		
 *		Constraints
 *			1 <= n <= 10^6
 *
 *		Example
 *			Input:	3
 *			Output:	3 10 5 16 8 4 2 1
 * 
 *************************************************************************************************/
void next_weird_number(int *num) {
	*num = *num % 2 ? *num * 3 + 1 : *num / 2;
}

void weird_algorithm(int *num) {
	while (num != 1) {
		printf("%d ", num);
		next_weird_number(&num);
	}
	printf("%d ", num);
}

void run_weird_algorithm() {
	// Weird Algorithm input constraint: 1 <= n <= 10^6
	srand(time(NULL));

	int max_num = 1;
	int min_num = pow(10, 6);

	int weird_num = rand() % (max_num - min_num) + min_num;
	printf("Randomly chosen number: %d\n", weird_num);
	printf("Output based on number: ");
	weird_algorithm(weird_num);
	
}
#pragma endregion


#pragma region missing_number
/*************************************************************************************************
 *
 *		You are given all numbers between 1,2,...,n except one. 
 *		Your task is to find the missing number.
 *
 *		Input
 *			The first input line contains an integer n.
 *
 *			The second line contains n-1 numbers. Each number is distinct and between 
 *			1 and n (inclusive).
 *
 *		Output
 *			Print the missing number.
 *
 *		Constraints
 *			2 <= n <= 2x10^5
 *
 *		Example
 *			Input:	5
 *					2 3 1 5
 *
 *			Output:	4
 *
 *************************************************************************************************/
int missing_num(size_t count, int numbers[]) {
	int found;
	int i, j;

	for (i = 1; i <= count; i++) {
		found = 0;
		
		for (j = 0; j < (count - 1); j++) {
			if (numbers[j] == i) {
				found = i;
				break;
			}
		}

		if (found == 0) {
			return i;
		}
	}
}

void run_missing_num() {
	int	i, j, t;
	int index_to_remove;
	int result;

	//generate array size randomly of size 2 to 2x10^5
	int max_array_size = 2 * pow(10, 5);
	int min_array_size = 2;
	int array_size = rand() % (max_array_size - min_array_size) + min_array_size;
	int array_size_plus_one = array_size + 1;

	//use calloc to create array dynamically - remember to free later on;
	int *numbers = (int*)calloc(array_size, sizeof(int));
	//print_array_with_message("numbers immediately after allocation", numbers, array_size);

	if (numbers == NULL) {
		fprintf(stderr, "Memory allocation failed!\n");
		return 1;
	}

	//Generate the array for testing the missing_num function
	printf("number of elements in array: %d\n", array_size);
 
	//Initialize the array in order
	for (i = 0; i < array_size; i++) {
		numbers[i] = i + 1;
	}
	//print_array_with_message("numbers after initial seeding", numbers, array_size);

	//Randomize array
	//generate random seed
	srand(time(NULL));
	for (i = 0; i < array_size; i++) {
		j = rand() % (array_size - i) + i;
		t = numbers[j];
		numbers[j] = numbers[i];
		numbers[i] = t;
	}
	//print_array_with_message("numbers after randomization", numbers, array_size);

	//Remove random index after randomization
	index_to_remove = rand() % array_size;
	printf("index removed: %d;   value: %d\n", index_to_remove, numbers[index_to_remove]);
	memmove(numbers + index_to_remove, numbers + index_to_remove + 1, (array_size - index_to_remove) * sizeof(numbers[0]));
	//print_array_with_message("numbers after random index removal", numbers, array_size - 1);
	
	result = missing_num(array_size_plus_one, numbers);
	printf("missing number was identified by algorithm as: %d\n", result);

	free(numbers);
}
#pragma endregion


int main() {
	helloworld();
	printf("\n\n*************************************************************\n\n");
	
	run_weird_algorithm();
	printf("\n\n*************************************************************\n\n");
	
	run_missing_num();	
	printf("\n\n*************************************************************\n\n");

	return 0;
}
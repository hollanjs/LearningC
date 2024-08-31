#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "weird_algorithm.h"

/*************************************************************************************************

	Consider an algorithm that takes as input a positive integer n. If n is even,
	the algorithm divides it by two, and if n is odd, the algorithm multiplies it
	by three and adds one. The algorithm repeats this, until n is one.

	For example, the sequence for n=3 is as follows:
	3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1

	Your task is to simulate the execution of the algorithm for a given value of n.

	Input
		The only input line contains an integer n.
 
	Output
		Print a line that contains all values of n during the algorithm.

	Constraints
		1 <= n <= 10^6

	Example
		Input:	3
		Output:	3 10 5 16 8 4 2 1

*************************************************************************************************/

void next_weird_number(int* num) {
	*num = *num % 2 ? *num * 3 + 1 : *num / 2;
}

void weird_algorithm(int* num) {
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
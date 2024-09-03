#include <stdio.h>

#include "increasing_array.h"
#include "..\..\utils\arr\arr.h"


/*************************************************************************************************

	You are given an array of n integers. You want to modify the array so that it is increasing, 
	i.e., every element is at least as large as the previous element.
	
	On each move, you may increase the value of any element by one. What is the minimum 
	number of moves required?

	Input
		The first input line contains an integer n: the size of the array.
		Then, the second line contains n integers x_1,x_2,...,x_n: the contents of the array.
	
	Output
		Print the minimum number of moves.
	
	Constraints
		1 <= n <= 2x10^5
		1 <= x_i <= 10^9

	Example
		Input:	5
				3 2 5 1 7
		Output:	5

	https://cses.fi/problemset/task/1094

**************************************************************************************************/



int get_minimum_moves(int *arr) {
	//IMPLEMENT
}


void run_increasing_array() {
	int* num_array = new_random_intarray(5);
	
	//print for debugging
	for (int i = 0; i < 5; i++) {
		printf("%d", num_array[i]);
	}
	printf("\n");
	
	//DO THE THING WITH THE ARRAY!

	free_array(num_array);
}
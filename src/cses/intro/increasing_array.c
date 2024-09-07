#include <stdio.h>

#include "..\..\utils\arr\arr.h"
#include "..\..\utils\cli\print.h"

#include "increasing_array.h"



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



int get_minimum_moves(int *arr, int size) 
{
	int i, moves, curr_max, delta;

	moves = 0;
	curr_max = arr[0];
	printf("Starting Max:       %d\n\n", curr_max);

	for (i = 1; i < size; i++) 
	{
		delta = 0;

		if (arr[i] < curr_max) 
		{
			delta = curr_max - arr[i];
			moves += delta;
			printf("Current Max: %2d;    Next Value: %2d;    Delta: %2d;    Total Moves: %3d\n", curr_max, arr[i], delta, moves);
		}
		else 
		{
			curr_max = arr[i];
			printf("Max Updated: %2d;    Number increased - no need to perform work...\n", curr_max);
		}
	}

	return moves;
}


void run_increasing_array() 
{
	printf("--------------------------  INCREASING ARRAY  --------------------------\n\n");
	int i, moves;

	int array_size = 15;
	int *num_array = new_random_intarray(array_size);
	
	//print for debugging
	print_array_with_message("Array to process:", num_array, array_size);
	
	
	//DO THE THING WITH THE ARRAY!
	moves = get_minimum_moves(num_array, array_size);
	printf("\nMoves required:     %d\n", moves);

	free_array(num_array);

	printf("\n\n\n\n");
}
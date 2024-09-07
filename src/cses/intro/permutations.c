#include <stdio.h>
#include <stdbool.h>

#include "..\..\utils\arr\arr.h"
#include "..\..\utils\cli\print.h"

#include "permutations.h"


/*************************************************************************************************

	A permutation of integers 1,2,...,n is called beautiful if there are no adjacent elements 
	whose difference is 1.
	
	Given n, construct a beautiful permutation if such a permutation exists.
	
	Input
		The only input line contains an integer n.
	
	Output
		Print a beautiful permutation of integers 1,2,...,n. If there are several solutions, 
		you may print any of them. If there are no solutions, print "NO SOLUTION".
	
	Constraints
		1 <= n <= 10^6

	Example 1
		Input:	5
		Output:	4 2 5 3 1
	
	Example 2
		Input:	3
		Output:	NO SOLUTION

	https://cses.fi/problemset/task/1070

**************************************************************************************************/


void make_segment_beautiful(int arr[], int start_index, int array_size) {
	/********************** GOAL **********************
	*
	*	Update a range of up to 5 indexes, so that the 
	*	diff between neighboring index is GT 1
	* 
	*	   START:  [ 1 2 3 4 5 ]
	*                  ^-^
	*	 UPDATED:  [ 1 3 2 4 5 ]
	*                    ^---^
	*	 UPDATED:  [ 1 3 5 4 2 ]
	*                      ^-^
	*	   FINAL:  [ 1 3 5 2 4 ]
	*
	***************************************************/

	// Only feasible if there are at least a range of 3 indexes
	if (start_index + 2 >= array_size)
		return;

	int src, dst;

	int action_count = 0;
	int max_actions = 3;

	while (action_count + start_index <  array_size
		            && ++action_count <= max_actions) 
	{
		switch (action_count)
		{
			case 1:
				src = start_index + 1;
				dst = start_index + 2;
				swap_indexes(arr, src, dst);
				break;
			case 2:
				src = start_index + 2;
				dst = start_index + 4;
				swap_indexes(arr, src, dst);
				break;
			case 3:
				src = start_index + 3;
				dst = start_index + 4;
				swap_indexes(arr, src, dst);
				break;
			default:
				break;
		}
	}
}

void beautiful_array(int arr[], int size) 
{
	int beautiful_buffer = 5;
	// Every array where size GE 5 has a solution
	if (size < beautiful_buffer)
	{
		printf("NO SOLUTION");
		return;
	}
	
	int i;
	bool beautifully_divisable;

	// Is divisible by beautiful_buffer (divisible by 5)
	beautifully_divisable = size % beautiful_buffer == 0;

	int iterations = beautifully_divisable ? size / beautiful_buffer : size / beautiful_buffer + 1;

	for (i = 0; i < iterations; i++)
	{
		make_segment_beautiful(arr, i * beautiful_buffer, size);
	}

	if (!beautifully_divisable)
		// swap first and last indexes
		swap_indexes(arr, 0, size - 1);

	//print_array(arr, size, "Beautiful array:");
	print_array_with_message("Beautiful array:", arr, size);
}


void run_permutations() 
{
	printf("--------------------------  PERMUTATIONS  --------------------------\n\n");

	int i;
	int array_size;

	array_size = 12;

	int* num_array = new_sequential_int_array(1, array_size, 1);
	print_array_with_message("Original array:", num_array, array_size);

	beautiful_array(num_array, array_size);

	free_array(num_array);
}
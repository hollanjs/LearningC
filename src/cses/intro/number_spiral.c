#include <stdio.h>
#include <math.h>

#include "number_spiral.h"

#define AXIS 2

/*************************************************************************************************

	A number spiral is an infinite grid whose upper-left square has number 1. 
	Here are the first five layers of the spiral:

		--------------------------      ---------------------
		| 1  | 2  | 9  | 10 | 25 |      | > | v | > | v | > ... and so on...
		--------------------------      ---------------------
		| 4  | 3  | 8  | 11 | 24 |      | v | < | ^ | v | ^ |
		--------------------------      ---------------------
		| 5  | 6  | 7  | 12 | 23 |      | > | > | ^ | v | ^ |
		--------------------------      ---------------------
		| 16 | 15 | 14 | 13 | 22 |      | v | < | < | < | ^ |
		--------------------------      ---------------------
		| 17 | 18 | 19 | 20 | 21 |      | > | > | > | > | ^ |
		--------------------------      ---------------------

	Your task is to find out the number in row y and column x.
	
	Input
		The first input line contains an integer t: the number of tests.
		After this, there are t lines, each containing integers y and x.
	
	Output
	 
		For each test, print the number in row y and column x.
	
	Constraints
		1 <=  t  <= 10^5
		1 <= y,x <=  

	Example
		Input:	3
				2 3
				1 1
				4 2
		Output:	8
				1
				15

	https://cses.fi/problemset/task/1071

**************************************************************************************************/



int spiral_algorithm_one(int a, int b)
{
	return (a - 1) * (a - 1) + b;
}

int spiral_algorithm_two(int a, int b)
{
	return a * a - b + 1;
}

int spiral_algorithm_three(int a, int b)
{
	return b * b - (a - 1);
}


int calculate_number(int y, int x)
{
	// if y >= x and y is odd
	if (y >= x && y % 2 == 1) 
		return spiral_algorithm_one(y, x);
	
	// if y >= x and y is even
	if (y >= x)
		return spiral_algorithm_two(y, x);

	// if y < x and x is odd
	if (x % 2 == 1)
		return spiral_algorithm_three(y, x);

	// if y < x and x is even
	return spiral_algorithm_one(x, y);
}


void find_numbers_in_spiral(int num_tests, int coordinates[][AXIS])
{
	int res;

	for (int i = 0; i < num_tests; i++) 
	{
		res = calculate_number(coordinates[i][0], coordinates[i][1]);
		printf("%d\n", res);
	}
}


void run_number_spiral() 
{
	printf("--------------------------  PERMUTATIONS  --------------------------\n\n");

	/*
		Input:		3
					2 3
					1 1
					4 2
		Output :	8
					1
					15
	*/

	int test_count = 10;
	int test_coords[][AXIS] = { 
		{ 2, 3 },	// 8
		{ 1, 1 },	// 1
		{ 4, 2 },	// 15 
		{ 3, 3 },	// 7
		{ 6, 6 },	// 31
		{ 8, 5 },	// 60
		{ 6, 3 },	// 34
		{ 2, 9 },	// 80
		{ 8, 10 },	// 89
		{ 10, 1 }	// 89
	};

	printf("Running %d tests...\nResults should be:  8, 1, 15, 7, 31, 60, 34, 80, 89, 100\n\n", test_count);

	find_numbers_in_spiral(test_count, test_coords);
}
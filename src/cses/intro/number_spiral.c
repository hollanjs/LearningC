#include <stdio.h>
#include <math.h>

#include "number_spiral.h"

#define AXIS 2

/*************************************************************************************************

	A number spiral is an infinite grid whose upper-left square has number 1. 
	Here are the first five layers of the spiral:

		--------------------------     
		| 1  | 2  | 9  | 10 | 25 |     
		--------------------------     
		| 4  | 3  | 8  | 11 | 24 |     
		--------------------------     
		| 5  | 6  | 7  | 12 | 23 |     
		--------------------------     
		| 16 | 15 | 14 | 13 | 22 |     
		--------------------------     
		| 17 | 18 | 19 | 20 | 21 |     
		--------------------------     

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

/************************************************************************************************************************************************
////////////////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

-- for this problem assume starting indexes are 1 (not 0) when counting rows and columns (not normal from a programming perspective)
-- 10x10 was chosen because I was figuring this out on paper and didn't want to write exponentially more...
-- below is translated from my paper to this file for later reference...


When looking at row 1 values, on a 10x10 spiral, the value of every ODD column is that column's index squared
-------------------------------------------------------------------------------------------------------------
index		   1     2     3     4      5      6      7      8      9      10
index is odd	   Y     N     Y     N      Y      N      Y      N      Y      N 
squared           1x1         3x3    	   5x5           7x7           9x9
                   |           |            |             |             |
                   v           v            v             v             v
value		|  1  |  2  |  9  |  10  |  25  |  26  |  49  |  50  |  81  |  82  |   
-------------------------------------------------------------------------------------------------------------

equally, when looking at column 1 values, on a 10x10 spiral, the value of every EVEN column index is that rows index squared
-------------------------------------------------------------------------------------------------------------
index	index is even	squared		value
1	N				1
2	Y		2x2   	-->  	4
3	N				5
4	Y		4x4   	-->  	16
5	N				17
6	Y		6x6   	-->  	36
7	N				37
8	Y		8x8   	-->  	64
9	N				65
10	Y		10x10  	-->  	100
-------------------------------------------------------------------------------------------------------------

If you look closely, you see the next numbers over or down appear to incredment by 1, because these squared values
are kind of like pivots in that is where the numbers whip around and start going in the other direction.

we can use these squares as starting points to start closer to the number we're trying to find rather than counting the whole spiral.

However, there is another pivot around where y = x, in that is where the numbers make a right turn and got from N/S <-> E/W. This is
the reason we need to determine if Y > X or vice versa.

      1   2   3   4   5
    ---------------------
1   | > | v | > | v | > ... and so on...
    ---------------------
2   | v | < | ^ | v | ^ |
    ---------------------
3   | > | > | ^ | v | ^ |
    ---------------------
4   | v | < | < | < | ^ |
    ---------------------
5   | > | > | > | > | ^ |
    ---------------------

so if Y is greater than X, we know that values will be incrementing +-1 as we move indexes left/right within the bounds of  1-> X on that row.
vice versa for X being greater than Y. We know that values will be incrementing +-1 as we move indexes up/down within the bounds of 1 -> Y on that col.

after working it out, you end up with something like:

Y > X
| Y is even?	y^2 - x + 1
| Y is odd?	(y - 1)^2 + x

Y = X
| Y is even?	y^2 - x + 1
| Y is odd?	(y - 1)^2 + x

Y < X
| X is even?	(x - 1)^2 + y
| X is odd?	x^2 - (y -1)		(spiral_algorithm_three())


You can see that Y > X and Y = X are the same, so we can combine those into:
Y >= X
| Y is even?	y^2 - x + 1		(spiral_algorithm_two())
| Y is odd?	(y - 1)^2 + x


And you might also see that the following are the same, but the Y and X are flipped in the operations:
Y >= X | Y is odd?	(y - 1)^2 + x
Y <  X | X is even?	(x - 1)^2 + y

so we can combine them together as well into a function, then swap Y with X based on which is greater.	(see spiral_algorithm_one())


See below code for implementation details and logic on how and when to call the algorithms based on Y and X values.  (see calculate_numbers())

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////////////////////////////////////////////////////////
************************************************************************************************************************************************/


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
	// root of spiral is always 1
	if (y == 1 && x == 1)
		return 1;

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

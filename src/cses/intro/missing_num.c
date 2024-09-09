#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "..\..\utils\print.h"
#include "..\..\utils\arr.h"
#include "..\..\utils\random.h"

#include "missing_num.h"

/*************************************************************************************************

    You are given all numbers between 1,2,...,n except one.
    Your task is to find the missing number.

    Input
        The first input line contains an integer n.

        The second line contains n-1 numbers. Each number is distinct and between
        1 and n (inclusive).

    Output
        Print the missing number.

    Constraints
        2 <= n <= 2x10^5

    Example
        Input:	5
                2 3 1 5
        Output:	4

 *************************************************************************************************/


int missing_num(int numbers[], int count)
{
    bool exists;
    int i, j;
    for (i = 1; i <= count; i++) 
    {
        exists = false;
        for (j = 0; j < (count - 1); j++) 
        {
            if (numbers[j] == i) 
            {
                exists = true;
                break;
            }
        }

        if (!exists)
            return i;
    }
}

void run_missing_num() 
{
    printf("--------------------------  MISSING NUMBER  --------------------------\n\n");
    //int	i;
    int result;

    //generate array size randomly of size 2 to 2x10^5
    int min_array_size = 2;
    int max_array_size = 2 * pow(10, 5);
	int array_size = new_random(min_array_size, max_array_size);
    //int array_size_plus_one = array_size + 1;


	/***********************************************************************************
	* 
	*   [ ] figure out best way to use new iarr for this
	* 
	*/
    //use calloc to create array dynamically - remember to free later on;
    int* numbers = NULL;

    //Generate the array for testing the missing_num function
	numbers = new_random_intarray(array_size);
    printf("number of elements in array: %d\n", array_size);

    //Remove random index after randomization
    remove_random_index(numbers, array_size);
    //print_array_with_message("numbers after random index removal", numbers, array_size - 1);

    //Get missing number that was pulled from the array
    result = missing_num(numbers, array_size);
    printf("missing number identified by algorithm: %d\n", result);

	free_array(numbers);

    printf("\n\n\n\n");
}
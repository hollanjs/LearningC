#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "console_utils.h"

//Problem sets
#include "weird_algorithm.h"
#include "missing_num.h"
#include "repetitions.h"
#include "increasing_array.h"
#include "permutations.h"
#include "number_spiral.h"
#include "two_knights.h"
#include "two_sets.h"


/*******************************************************************************************
 *	
 *	Problem sets can be found:
 *	https://cses.fi/problemset/list/
 * 
 *	Each problem should contain a function 'run_<problem_name>()' function that displays 
 *	the proper outout, including any additional details to the console.
 *
 *******************************************************************************************/


int main() {	
	run_weird_algorithm();
	printf("\n\n*************************************************************\n\n");
	
	run_missing_num();	
	printf("\n\n*************************************************************\n\n");

	//run_repetitions();		/*Needs implementation*/
	//printf("\n\n*************************************************************\n\n");

	//run_increasing_array();	/*Needs implementation*/
	//printf("\n\n*************************************************************\n\n");

	//run_permutations();		/*Needs implementation*/
	//printf("\n\n*************************************************************\n\n");

	//run_number_spiral();		/*Needs implementation*/
	//printf("\n\n*************************************************************\n\n");

	//run_two_knights();		/*Needs implementation*/
	//printf("\n\n*************************************************************\n\n");

	//run_two_sets();			/*Needs implementation*/
	//printf("\n\n*************************************************************\n\n");

	return 0;
}
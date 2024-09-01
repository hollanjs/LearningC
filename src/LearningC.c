#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#include "utils/conv/temp.h"
#include "utils/cli/print.h"

//Problem sets
#include "cses/intro/weird_algorithm.h"
#include "cses/intro/missing_num.h"
#include "cses/intro/repetitions.h"
#include "cses/intro/increasing_array.h"
#include "cses/intro/permutations.h"
#include "cses/intro/number_spiral.h"
#include "cses/intro/two_knights.h"
#include "cses/intro/two_sets.h"


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
	/*UTILITIES*/
	//test_temp_conversions();

	/*CSES PROBLEMS*/
	//run_weird_algorithm();
	//printf("\n\n*************************************************************\n\n");
	
	//run_missing_num();	
	//printf("\n\n*************************************************************\n\n");

	run_repetitions();		/*complete todo's listed in C file*/
	printf("\n\n*************************************************************\n\n");

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
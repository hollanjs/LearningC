//Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <assert.h>

//Utilities
#include "utils/conv/temp.h"
#include "utils/cli/print.h"
#include "utils/arr/test_iarr.h"

//Problem sets
#include "cses/intro/weird_algorithm.h"
#include "cses/intro/missing_num.h"
#include "cses/intro/repetitions.h"
#include "cses/intro/increasing_array.h"
#include "cses/intro/permutations.h"
#include "cses/intro/number_spiral.h"
#include "cses/intro/two_knights.h"
#include "cses/intro/two_sets.h"
#include "cses/intro/bit_strings.h"
#include "cses/intro/trailing_zeros.h"
#include "cses/intro/coin_piles.h"
#include "cses/intro/palindrome_reorder.h"
#include "cses/intro/gray_code.h"
#include "cses/intro/tower_of_hanoi.h"
#include "cses/intro/creating_strings.h"
#include "cses/intro/apple_division.h"
#include "cses/intro/chessboard_and_queens.h"
#include "cses/intro/digit_queries.h"
#include "cses/intro/grid_paths.h"


/*******************************************************************************************
 *	
 *	Problem sets can be found:
 *	https://cses.fi/problemset/list/
 * 
 *	Each problem should contain a function 'run_<problem_name>()' function that displays 
 *	the proper outout, including any additional details to the console.
 *
 *******************************************************************************************/


int main() 
{	
	/*********************  UTILITIES  *********************/
	// TO-DO:
	// [ ] complete iarr function suggestions
	
    //test_temp_conversions();
	run_iarr_tests();


    /*******************  CSES PROBLEMS  *******************/
	// TO-DO:
	// [ ] cutover CSES problems to use new iarr type
	// [ ] repetitions - line 90 - create carr version of iarr to assist
	//     with dynamically creating char arrays

	run_weird_algorithm();
	run_missing_num();	
	run_repetitions();				
	run_increasing_array();
	run_permutations();		
	run_number_spiral();		
	//run_two_knights();			/*Hold - learn combinatorics*/
    //run_two_sets();				/*Needs implementation*/
	//run_bit_strings();			/*Needs implementation*/
	//run_trailing_zeros();			/*Needs implementation*/
	//run_coin_piles();				/*Needs implementation*/
	//run_palindrome_reorder();		/*Needs implementation*/
	//run_gray_code();				/*Needs implementation*/
	//run_tower_of_hanoi();			/*Needs implementation*/
	//run_creating_strings();		/*Needs implementation*/
	//run_apple_division();			/*Needs implementation*/
	//run_chessboard_and_queens();	/*Needs implementation*/
	//run_digit_queries();			/*Needs implementation*/
	//run_grid_paths();				/*Needs implementation*/

    return 0;
}
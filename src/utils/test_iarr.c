#include <stdio.h>

#include "arr.h"


void print_test(iarr arr, char message[])
{
	printf("%s:\n", message);
	print_iarr(arr);
}

void run_iarr_tests() {
	// blank test
	iarr blank_iarr = new_iarr(5);
	print_test(blank_iarr, "Contents of blank_iarr");
	free_iarr(blank_iarr);

	//sequential test
	iarr sequential_iarr = new_sequential_iarr(1,10,1);
	print_test(sequential_iarr, "Contents of sequential_iarr");
	
	//randomize sequential test
	randomize_iarr(sequential_iarr);
	print_test(sequential_iarr, "Contents of sequential_iarr after randomization");
	free_iarr(sequential_iarr);


	//new random test
	iarr random_iarr = new_random_iarr(7);
	print_test(random_iarr, "Contents of new random_iarr of size 7");
	free_iarr(random_iarr);
}
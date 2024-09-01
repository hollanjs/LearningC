#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "repetitions.h"

#define MAX_STRING 1000000


/*************************************************************************************************

	You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task 
	is to find the longest repetition in the sequence. This is a maximum-length substring 
	containing only one type of character.

	Input
		The only input line contains a string of n characters.

	Output
		Print one integer: the length of the longest repetition.

	Constraints
		1 <= n <= 10^6

	Example
		Input:	ATTCGGGA
		Output:	3

	https://cses.fi/problemset/task/1069

**************************************************************************************************/


int max_char_repition(char line[]) {
	int i, j, k;

	int max			= 0;
	int char_count	= strlen(line);

	for (i = 0; i < char_count; i++) {
		if ((char_count - i) < max)
			break;

		for (j = i, k = 1; line[j] == line[i]; j++, k++) {
			if (max < k)
				max++;
		}
	}

	return max;
}


void run_repetitions() {
	int res;
	printf("Running repetition assertions against faux DNA strings...\n");

	res = max_char_repition("ATTTTTTTTCGGGGA");
	assert(res == 8);

	res = max_char_repition("AAAATAAAATAAAATAAAATAAAATAAAATAAAATAAAATAAAATAAAATAAAA");
	assert(res == 4);

	res = max_char_repition("ACTACCTAACACAAGACATAGACACAT");
	assert(res == 2);

	res = max_char_repition("GAACTGATCCGGTAACTTGAACGTTCCGTCAGTGGCATGGGG");
	assert(res == 4);

	res = max_char_repition("CTTTCAGG");
	assert(res == 3);

	res = max_char_repition("A");
	assert(res == 1);

	res = max_char_repition("TT");
	assert(res == 2);

	res = max_char_repition("TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT");
	assert(res == 106);

	//try generating long strings of same pattern...
	//TODO: Turn creation of dynamic sized char arrays into a function that returns a pointer to start of array
	char *long_string = (char*)malloc((MAX_STRING + 1) * sizeof(char));
	if (long_string == NULL) {
		fprintf(stderr, "REPETITIONS:: Memory allocation failed for long_string!\n");
		return 1;
	}

	char dna_pattern[] = "ATGC";
	int pattern_len = strlen(dna_pattern);
	
	for (int i = 0; i < MAX_STRING; i++) {
		long_string[i] = dna_pattern[i % pattern_len];
	}
	long_string[MAX_STRING] = '\0';

	res = max_char_repition(long_string);
	assert(res == 1);

	free(long_string);


	//try generating long strings of same char...
	char* same_char = (char*)malloc((MAX_STRING + 1) * sizeof(char));
	if (same_char == NULL) {
		fprintf(stderr, "REPETITIONS:: Memory allocation failed for long_string!\n");
		return 1;
	}

	for (int i = 0; i < MAX_STRING; i++) {
		same_char[i] = 'A';
	}
	same_char[MAX_STRING] = '\0';

	res = max_char_repition(same_char);
	assert(res == MAX_STRING);

	free(same_char);



	printf("All assertions passed!\n");
}
#include <stdio.h>
#include <string>
#include <assert.h>

#include "repetitions.h"


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

	printf("All assertions passed!\n");
}
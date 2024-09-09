#include <stdlib.h>
#include <time.h>

#include "random.h"

int new_random(int min, int max)
{
	srand(time(NULL));
	return rand() % (max - min) + min;
}


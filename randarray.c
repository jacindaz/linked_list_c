#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "randarray.h"

static int data[10];

int* get_rand_array(void)
{
	int i = 0;
	srand( time(NULL) );

	for(i = 0; i < 10; i++)
	{
		data[i] = ( rand() & 0x000000ff );
	}

	for(i = 0; i < 10; i++)
	{
		printf("%d ", data[i] );
	}
	printf("\n");
	return data;
}


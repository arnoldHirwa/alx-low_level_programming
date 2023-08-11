#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int n;
	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* MY CODES */
	if (n > 0)
	{
	printf("%d is positve\n", n);
	}
	else if (n == 0)
	{
	printf("%d is zero\n", n);
	}
	else
	{
	printf("%d is negative\n", n);
	}

	return 0;
}

#include <stdlib.h>

#include <time.h>
#include <stdio.h>

/**
 *main - return different combinations of 2 digits
 *
 * Return: Always (success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			putchar('0' + i);
			putchar('0' + j);

			if (i == 8 && j == 9)
				continue;

			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}

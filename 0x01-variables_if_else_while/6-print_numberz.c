#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 *main - a function that returns digits in base 10
 *
 * Return: Always (success)
 */
int main(void)
{
	int n, lastdig;

	for (n = '0'; n <= '9'; n++)
	{
		putchar(n);
	}

	putchar('\n');

	return (0);
}

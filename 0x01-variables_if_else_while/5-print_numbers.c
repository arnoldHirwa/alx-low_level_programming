#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints number from 0 to 9
 *
 * Return: Always (success)
 */
int main(void)
{
	char n;

	for (n = '0'; n <= '9'; n++)
	{
		putchar(n);
	}

	putchar('\n');

	return (0);
}

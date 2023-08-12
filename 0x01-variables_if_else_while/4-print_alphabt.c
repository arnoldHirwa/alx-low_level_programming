#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints all letters except q and e
 *
 * Return: Always (success)
 */
int main(void)
{
	char d;

	for (d = 'a'; d <= 'z'; d++)
	{
		if (d != 'e' && d != 'q')
		{
			putchar(d);
		}
	}
	putchar('\n');

	return (0);
}

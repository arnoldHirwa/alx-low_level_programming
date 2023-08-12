#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 *main - Return alphabets in reverse
 *
 * Return: Always (success)
 */
int main(void)
{
	char c;

	for (c = 'z'; c >= 'a'; c--)
	{
		putchar(c);
	}

	putchar('\n');

	return (0);
}

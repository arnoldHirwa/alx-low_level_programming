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
	int c, i;

	c = i = '0';

	for (c = '0'; c <= '8'; c++)
	{
		for (i = c + 1; i <= '9'; i++)
		{
			putchar((c % 10) + '0');
			putchar((i % 10) + '0');

			if ((c == '8') && (c == '9'))
				continue;
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 *main - combination of 2 letters in different ways
 *
 * Return: Always (success)
 */
int main(void)
{
	int k, c, j, i;

	for (c = 48; c <= 57; c++)
	{
		for (i = 48; i <= 57; i++)
			for (k = 48; k <= 57; k++)
				for (j = 48; j <= 57; j++)
				{
					if (((k + j) > (c + i) && k >= c) || c < k)
					{
						putchar(c);
						putchar(i);
						putchar(' ');
						putchar(k);
						putchar(j);

						if (c + i + k + j == 227 && c == 57)
						{
							break;
						}
						else
						{
							putchar(',');
							putchar(' ');
						}
					}
				}
	}

	putchar('\n');

	return (0);
}

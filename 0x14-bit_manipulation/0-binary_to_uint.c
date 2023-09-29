#include "main.h"
/**
 * binary_to_uint - converts a binary to an unsigned int
 * @b: the binary number as a string
 *
 * Return: the converted value
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int integer = 0;

	if (b == NULL)
		return (0);

	for ( ; *b != '\0'; b++)
	{
		if ((*b != '0') && (*b != '1'))
			return (0);
		integer = integer << 1;
		if (*b == '1')
		{
			integer = integer | 2;
		}
	}

	return (integer);
}

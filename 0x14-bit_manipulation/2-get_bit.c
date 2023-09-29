#include "main.h"

/**
*get_bit - get the value of a bit at the given index
*@n: the number
*@index: index starting from 0 of the bit required
*
*Return: The converted value
*/

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	return (n >> index & 1);
}

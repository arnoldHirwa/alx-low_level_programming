#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - sums all arguments passed
 *
 * @n: number of arguments
 *
 * Return: sum of arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	int total;
	unsigned int m = 0;

	va_list args;

	va_start(args, n);
	total = 0;
	while (m++ < n)
	{
		total += va_arg(args, int);
	}

	va_end(args);
	return (total);
}

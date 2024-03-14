#include "search_algos.h"

/**
 * recursive_check - searches for a value binarly
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int recursive_check(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (recursive_check(array, half, value));

	half++;

	return (recursive_check(array + half, size - half, value) + half);
}

/**
 * binary_search - calls to binary_search to return
 * the index of the number
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	index = recursive_check(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}

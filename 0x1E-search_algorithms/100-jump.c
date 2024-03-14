#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches using jump search
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: id of the number
 */
int jump_search(int *array, size_t size, int value)
{
	int id, m, k, prev;

	if (array == NULL || size == 0)
		return (-1);

	m = (int)sqrt((double)size);
	k = 0;
	prev = id = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", id, array[id]);

		if (array[id] == value)
			return (id);
		k++;
		prev = id;
		id = k * m;
	} while (id < (int)size && array[id] < value);

	printf("Value found between ides [%d] and [%d]\n", prev, id);

	for (; prev <= id && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}

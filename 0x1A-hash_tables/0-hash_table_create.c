#include "hash_tables.h"

/**
* hash_table_create - creates a hash table
* @size: the size of the array
*
* Return: pointer to the new created table or null if it failed
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = malloc(sizeof(hash_table_t));
	hash_node_t **array = malloc(sizeof(hash_node_t) * size);
	unsigned long int n;

	if (new_table == NULL || array == NULL || size == 0)
	{
		if (new_table)
			free(new_table);
		if (array)
			free(array);
		return (NULL);
	}

	new_table->size = size;
	new_table->array = array;

	for (n = 0; n < size; n++)
		new_table->array[n] = NULL;
	return (new_table);
}

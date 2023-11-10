#include "lists.h"

/**
* dlistint_len - returns number of elements in a linked dlistint_t list.
* @h: pointer to the head of the list
*
* Return: number of nodes
*/

size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	if (h == NULL)
	{
		return (len);
	}
	if (h->prev != NULL)
	{
		h = h->prev;
		while (h->prev != NULL)
		{
			h = h->prev;
		}
	}
	while (h != NULL)
	{
		h = h->next;
		len++;
	}

	return (len);
}

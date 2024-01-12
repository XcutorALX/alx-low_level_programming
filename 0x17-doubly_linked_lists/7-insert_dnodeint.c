#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 *
 * @h: the head of the list
 * @idx: the index to be inserted at
 * @n: the data to insert into the list
 *
 * Return: the address of the new node
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int current;
	dlistint_t *currentNode, *new;
	
	if (idx == 0)
		return (add_dnodeint(h, n));

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;

	if (*h == NULL)
		return (NULL);

	currentNode = *h;
	while (currentNode->prev != NULL)
		currentNode = currentNode->prev;

	for (current = 1; currentNode != NULL; current++)
	{
		if (current == idx)
		{
			if (currentNode->next == NULL)
				return (add_dnodeint_end(h, n));

			new->prev = currentNode;
			new->next = currentNode->next;
			currentNode->next->prev = new;
			currentNode->next = new;
			return (new);
		}
		currentNode = currentNode->next;
	}
	return (NULL);
}

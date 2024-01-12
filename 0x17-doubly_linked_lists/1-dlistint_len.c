#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 *
 * @h: a pointer to the head of the list
 *
 * Return: the size of the list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count;
	dlistint_t *current;

	if (h == NULL)
		return (0);

	if (h->next == NULL)
		return (1);

	current = h->next->prev;

	while (current->prev != NULL)
		current = current->prev;

	for (count = 0; current != NULL; count++)
		current = current->next;

	return (count);
}

#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 *
 * @h: a pointer to the head of the list
 *
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes;
	dlistint_t *current;

	if (h == NULL)
		return (0);

	if (h->next == NULL)
	{
		printf("%d\n", h->n);
		return (1);
	}

	current = h->next->prev;
	while (current->prev != NULL)
		current = current->prev;

	for (nodes = 0; current != NULL; nodes++)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	return (nodes);
}

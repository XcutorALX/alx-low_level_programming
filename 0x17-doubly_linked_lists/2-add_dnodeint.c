#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - adds a node at the beginning of a dlistint_t list
 *
 * @head: the head of the list
 * @n: the value of the node to add
 *
 * Return: the address of the new element or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	if (*head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while ((*head)->prev != NULL)
		head = &((*head)->prev);

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	(*head)->prev = new;
	*head = new;

	return (new);
}

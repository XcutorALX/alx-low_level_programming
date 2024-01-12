#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a node at the end of a dlistint_t list
 *
 * @head: the head of the list
 * @n: the value of the node to add
 *
 * Return: the address of the new element or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

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
	
	current = *head;
	while (current->next != NULL)
		current = current->next;

	new->n = n;
	new->next = NULL;
	new->prev = current;
	current->next = new;

	return (new);
}

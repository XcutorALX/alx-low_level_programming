#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a dlistint_t list
 *
 * @head: a pointer to the head of the list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head == NULL)
		return;

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

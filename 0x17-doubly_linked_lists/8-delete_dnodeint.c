#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index {index}
 *
 * @head: the head of the list
 * @index: the index of the node to delete
 *
 * Return: 1 if successful and -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int current;
	dlistint_t *currentNode;

	if (*head == NULL)
		return (-1);

	currentNode = *head;
	while (currentNode->prev != NULL)
		currentNode = currentNode->prev;

	for (current = 0; currentNode != NULL; current++)
	{
		if (current == index)
		{
			currentNode->prev->next = currentNode->next;
			if (currentNode->next != NULL)
				currentNode->next->prev = currentNode->prev;
			return (1);
		}
		currentNode = currentNode->next;
	}
	return (-1);
}

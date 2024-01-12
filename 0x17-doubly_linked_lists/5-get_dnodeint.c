#include "lists.h"

/**
 * get_dnodeint_at_index - gets the integer at the specifies node of a dlistint_t list
 *
 * @head: the head of the list
 * @index: the index of the node to find
 *
 * Return: a pointer to the node with the index passed, or NULL if it DNE
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int current;
	dlistint_t *currentNode;

	if (head == NULL)
		return (NULL);

	currentNode = head;
	for (current = 0; currentNode->next != NULL; current++)
	{
		if (current == index)
			return (currentNode);
		currentNode = currentNode->next;
	}
	return (NULL);
}

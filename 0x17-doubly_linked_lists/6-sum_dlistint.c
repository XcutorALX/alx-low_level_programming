#include "lists.h"

/**
 * sum_dlistint - sums all the data of a dlistint_t list
 *
 * @head: the head of the list
 *
 * Return: returns the sum of the list
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

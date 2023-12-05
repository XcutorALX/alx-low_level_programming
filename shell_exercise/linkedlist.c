#include <stdio.h>
#include "main.h"

/**
 * list_l: creates an empty linked list
 *
 * Return: returns a pointer to the list
 */
list_l *createList(void)
{
	list_l *list = (list_l *)malloc(sizeof(list_l));

	if (!list)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	list -> head = NULL;
	list -> size  = 0;

	return list;
}

/**
 * add_node: creates and adds a new node to a linked list
 *
 * value: item to be added to the list
 *
 * return: returns 1 on success and 0 on failure
 */

int add_node(list_l *list, char *item)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	Node *currentNode;

	if (!newNode)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	newNode -> data = item;
	newNode -> next = NULL;

	if (!(list -> head))
	{
		list -> head = newNode;
		list -> size += 1;
	}
	else
	{
		currentNode = list -> head;

		while (currentNode -> next != NULL)
		{
			currentNode = currentNode -> next;
		}

		currentNode -> next = newNode;
		list -> size += 1;
	}

	return (1);
}

/**
 * print_list - prints all items in a linked list
 *
 * @list: the list to be printed
 *
 * Return: always 0
 */

int print_list(list_l *list)
{
	Node *currentNode;

	if (!(list -> head))
	{
		return 0;
	}
	
	currentNode = list -> head;
	
	while (currentNode != NULL)
	{
		printf("%s\n", currentNode -> data);
		currentNode = currentNode -> next;
	}

	return 0;
}

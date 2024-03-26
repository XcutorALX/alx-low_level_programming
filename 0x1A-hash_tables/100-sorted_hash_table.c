#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * shash_table_set - adds an element/key to a hash table
 *
 * @ht: the hash table
 * @key: the key to add
 * @value: the element the key should map to
 *
 * Return: 1 on succes 0 on failure
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned int index;
	char *valueDup, *keyDup;
	shash_node_t *tmp, *new;

	if (ht == NULL || strcmp(key, "") == 0 ||
		key == NULL || value == NULL)
		return (0);

	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (0);
	valueDup = strdup(value);
	keyDup = strdup(key);

	new->key = keyDup;
	new->value = valueDup;
	new->next = NULL;
	new->sprev = NULL;
	new->snext = NULL;

	index = key_index((const unsigned char *)key, ht->size);
	if ((ht->array)[index] == NULL)
		(ht->array)[index] = new;
	else
	{
		tmp = (ht->array)[index];
		while (tmp != NULL)
		{
			if (strcmp(tmp->key, keyDup) == 0)
			{
				free(tmp->value);
				free(new->key);
				free(new);
				tmp->value = valueDup;
				return (1);
			}
			tmp = tmp->next;
		}
		tmp = (ht->array)[index];
		new->next = tmp;
		(ht->array)[index] = new;
	}
	insert_helper(ht, new);
	return (1);
}

/**
 * insert_helper - this function helps find the right place to insert a node
 *
 * @ht: the hash table
 * @node: the node to be inserted
 *
 * Return: 1 on success 0 on failure
 */

int insert_helper(shash_table_t *ht, shash_node_t *node)
{
	int comp, revComp;
	shash_node_t *current, *rev;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	for (current = ht->shead, rev = ht->stail; current != NULL;
			current = current->snext, rev = rev->sprev)
	{
		comp = strcmp(node->key, current->key);
		revComp = strcmp(node->key, rev->key);
		if (comp < 0)
		{
			node->snext = current;
			node->sprev = current->sprev;
			if (current->sprev != NULL)
				current->sprev->snext = node;
			else
				ht->shead = node;
			current->sprev = node;
			return (1);
		}
		else if (revComp > 0)
		{
			node->snext = rev->snext;
			node->sprev = rev;
			if (rev->snext != NULL)
				rev->snext->sprev = node;
			else
				ht->stail = node;
			rev->snext = node;
			return (1);
		}
	}
	return (0);
}

/**
 * shash_table_create - creates an empty hash table
 *
 * @size: the size of the table to create
 *
 * Return: returns a pointer to the hash table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *newTable;

	if (size == 0)
		return (NULL);

	newTable = malloc(sizeof(shash_table_t));

	if (!newTable)
		return (NULL);

	newTable->size = size;
	newTable->array = calloc(size, sizeof(hash_node_t *));
	newTable->shead = NULL;
	newTable->stail = NULL;

	if (!(newTable->array))
	{
		free(newTable);
		return (NULL);
	}

	return (newTable);
}

/**
 * shash_table_get - gets an element from a hash table
 *
 * @key: the key to search for
 * @ht: the hash table
 *
 * Return: the value of the element, or NULL if key wasn't found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned int index;
	shash_node_t *tmp;

	if (ht == NULL || key == NULL ||
			strcmp(key, "") == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = (ht->array)[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}


/**
 * shash_table_print - prints all the elements in a hash table
 *
 * @ht: the hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	unsigned int first;

	if (ht == NULL)
		return;

	first = 0;
	printf("{");

	current = ht->shead;
	while (current != NULL)
	{
		if (first != 0)
			printf(", ");
		else
			first = 1;

		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 *
 * @ht: the hash table to delete
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *tmp;

	current = ht->shead;

	while (current != NULL)
	{
		tmp = current;
		current = current->snext;
		free(tmp->value);
		free(tmp->key);
		free(tmp);
	}

	free(ht->array);
	free((void *)ht);
}

/**
 * shash_table_print_rev - prints a hash table in reverse
 *
 * @ht: the hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	unsigned int first;

	if (ht == NULL)
		return;

	first = 0;
	printf("{");

	current = ht->stail;
	while (current != NULL)
	{
		if (first != 0)
			printf(", ");
		else
			first = 1;

		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
	}

	printf("}\n");
}

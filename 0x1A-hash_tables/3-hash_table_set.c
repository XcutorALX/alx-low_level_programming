#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - adds an element/key to a hash table
 *
 * @ht: the hash table
 * @key: the key to add
 * @value: the element the key should map to
 *
 * Return: 1 on succes 0 on failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned int index;
	char *valueDup, *keyDup;
	hash_node_t *tmp, *new;

	if (ht == NULL || strcmp(key, "") == 0)
		return (0);

	new = malloc(sizeof(hash_node_t));

	if (!new)
		return (0);

	valueDup = strdup(value);
	keyDup = strdup(key);

	new->key = keyDup;
	new->value = valueDup;
	new->next = NULL;

	index = key_index((const unsigned char *)key, ht->size);

	if ((ht->array)[index] == NULL)
		(ht->array)[index] = new;
	else
	{
		tmp = (ht->array)[index];
		new->next = tmp;
		(ht->array)[index] = tmp;
	}

	return (1);
}

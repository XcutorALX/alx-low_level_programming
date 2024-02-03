#include "hash_tables.h"
#include <stddef.h>
#include <string.h>

/**
 * hash_table_get - gets an element from a hash table
 *
 * @key: the key to search for
 * @ht: the hash table
 *
 * Return: the value of the element, or NULL if key wasn't found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int index;
	hash_node_t *tmp;

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

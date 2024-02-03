#include "hash_tables.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * hash_table_delete - deletes a hash table
 *
 * @ht: the hash table to delete
 */

void hash_table_delete(const hash_table_t *ht)
{
	hash_node_t *current, *tmp;
	unsigned int i;

	for (i = 0; i < ht->size; i++)
	{
		current = (ht->array)[i];

		while (current != NULL)
		{
			tmp = current;
			current = current->next;
			free(tmp->value);
			free(tmp->key);
			free(tmp);
		}
	}

	free(ht->array);
	free((void *)ht);
}

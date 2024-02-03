#include "hash_tables.h"
#include <stddef.h>
#include <stdio.h>


/**
 * hash_table_print - prints all the elements in a hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current;
	unsigned int i, first;

	if (ht == NULL)
		return;

	first = 0;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = (ht->array)[i];
		if (current != NULL)
		{
			while (current != NULL)
			{
				if (first != 0)
					printf(", ");
				else
					first = 1;

				printf("'%s': '%s'", current->key, current->value);
				current = current->next;
			}
		}
	}
	printf("}\n");
}

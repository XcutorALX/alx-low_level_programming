#include "hash_tables.h"

/**
 * key_index - finds the key index of a string by hashing
 *
 * @key: the key to search
 * @size: the size of the hash table
 *
 * Return: the index from hashing
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);
	return (hash % size);
}

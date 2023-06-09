#include "hash_tables.h"
/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    /* declare a pointer for the new table */
	hash_table_t *new_table = NULL;

    /* declare a variable for loop */
	unsigned long int i;

    /* if size is less than 1, return NULL */
	if (size < 1)
		return (NULL);

    /* allocate memory for the table itself */
	new_table = malloc(sizeof(hash_table_t));

    /* if allocation failed, return NULL */
	if (new_table == NULL)
		return (NULL);

    /* allocate memory for the array of nodes in the table */
	new_table->array = malloc(sizeof(hash_node_t *) * size);

    /* if allocation failed, free the table and return NULL */
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

    /* set the size of the table */
	new_table->size = size;

    /* initialize all nodes in the table to NULL */
	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

    /* return the newly created table */
	return (new_table);
}
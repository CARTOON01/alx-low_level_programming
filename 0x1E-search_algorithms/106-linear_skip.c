#include "search_algos.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: a pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp;

	if (!list)
		return (NULL);

	for (temp = list, list = list->express; ; temp = list, list = list->express)
	{
		if (list)
			printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		if (!list || list->n >= value)
		{
			if (!list)
			{
				list = temp;
				while (list->next)
					list = list->next;
			}
			printf("Value found between indexes [%ld] and [%ld]\n",
					temp->index, list->index);
			break;
		}
	}

	while (temp && temp->index <= list->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}

	return (NULL);
}
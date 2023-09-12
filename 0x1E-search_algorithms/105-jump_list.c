#include "search_algos.h"
/**
 * jump_list - searches for a value in a sorted list of integers
 * using the Jump search algorithm
 * @list: a pointer to the head of the list to search in
 * @size: the number of nodes in list
 * @value: the value to search for
 * Return: a pointer to the first node where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *ptr, *temp;
	size_t step, i, prev;

	if (!list)
		return (NULL);

	ptr = list;
	temp = ptr;
	step = sqrt(size);
	i = step;
	prev = i;

	while (ptr)
	{
		if (ptr->index == i)
		{
			printf("Value checked at index [%ld] = [%d]\n", i, ptr->n);
			if (ptr->n >= value || i == size - 1)
			{
				printf("Value found between indexes [%ld] and [%ld]\n", prev, i);
				break;
			}
			temp = ptr;
			prev = i;
			i += step;
			i = i >= size ? size - 1 : i;
		}
		ptr = ptr->next;
	}
	while (temp && temp->index <= ptr->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
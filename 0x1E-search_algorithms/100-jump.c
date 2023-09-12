#include "search_algos.h"
/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the first index where value is located
 */
int jump_search(int *array, size_t size, int value)
{
	int m, n, i, step;
	int new;

	if (!array)
		return (-1);
	new = (int) size;
	step = sqrt(new);

	for (i = 0; ; i++)
	{
		m = step * i;
		if (m >= new || array[m] >= value)
		{
			n = step * (i - 1);
			n = n < 0 ? 0 : n;
			printf("Value found between indexes [%d] and [%d]\n", n, m);
			break;
		}
		printf("Value checked array[%d] = [%d]\n", m, array[m]);
	}
	while (n < new)
	{
		printf("Value checked array[%d] = [%d]\n", n, array[n]);
		if (array[n] == value)
			return (n);
		n++;
	}

	return (-1);
}
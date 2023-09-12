#include "search_algos.h"
/**
 * print_array - prints the array
 * @array: pointer to first element of array
 * @left: left index
 * @right: right index
 * Return: void
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");

	for (i = left; i < right; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);
}

/**
 * recurse_array - iterates array recursively to find index of value
 * @array: the array
 * @left: left index
 * @right: right index
 * @value: value to search for
 * Return: index of value
 */
int recurse_array(int *array, int left, int right, int value)
{
	int mid;

	print_array(array, left, right);
	mid = (left + right) / 2;

	if (array[mid] == value)
		return (mid);
	if (left == right)
		return (-1);
	if (value > array[mid])
		return (recurse_array(array, mid + 1, right, value));
	else
		return (recurse_array(array, left, mid - 1, value));
}
/**
 * power - calculates power of to base 2
 * @n: exponent
 * Return: power
 */
size_t power(size_t n)
{
	size_t p = 1;

	while (n)
	{
		p *= 2;
		n--;
	}


	return (p);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the first index where value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, step = 1, first;

	if (!array)
		return (-1);
	for (i = 1; step < size; i++)
	{
		if (array[step] >= value)
			break;
		printf("Value checked array[%ld] = [%d]\n", step, array[step]);
		step = power(i);
	}
	first = step / 2;
	step = step >= size ? size - 1 : step;
	printf("Value found between indexes [%ld] and [%ld]\n", first, step);

	return (recurse_array(array, first, step, value));
}
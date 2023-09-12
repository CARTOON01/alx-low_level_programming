#include "search_algos.h"
/**
 * interpolation_recurse - uses interpolation to recurse array
 * @array: pointer to first element of array
 * @low: left index of subarray
 * @high: right index of subarray
 * @value: value being searched for
 * @size: size of array
 * Return: index where value is located
 */
int interpolation_recurse(int *array, size_t low, size_t high,
		int value, size_t size)
{
	size_t pos;

	pos = low + (((double)(high - low) /
				(array[high] - array[low])) * (value - array[low]));
	if (pos > size)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}
	printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
	if (array[pos] == value)
		return (pos);
	if (low == high)
		return (-1);
	if (array[pos] > value)
		return (interpolation_recurse(array, low, pos - 1, value, size));
	else
		return (interpolation_recurse(array, pos + 1, high, value, size));
}
/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the first index where value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (interpolation_recurse(array, 0, size - 1, value, size));
}
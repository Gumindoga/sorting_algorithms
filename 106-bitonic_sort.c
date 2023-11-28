#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap(int *ax, int *bx)
{
	int hold = *ax;
	*ax = *bx;
	*bx = hold;
}

/**
 * sequence_compare - Compares and sorts two integers in bitonic sequence.
 * @direct: A flag for sorting direction
 * @array: An array of integers.
 * @n: The size of the array.
 */

void sequence_compare(int direct, int *array, size_t n)
{
	size_t travel = n / 2;
	size_t i = 0;

	for (; i < travel; i++)
	{
		if ((array[i] > array[i + travel]) == direct)
		{
			swap(&array[i], &array[i + travel]);
			print_array(array, n);
		}
	}
}

/**
 * recursive_bitonic - Helper function to sort a bitonic sequence recursively.
 * @direct: A flag for sorting direction
 * @array: An array of integers.
 * @size: The size of the array.
 */

void recursive_bitonic(int direct, int *array, size_t size)
{
	if (size < 2)
		return;

	recursive_bitonic(1, array, size / 2);
	recursive_bitonic(0, array + size / 2, size / 2);
	sequence_compare(direct, array, size);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 * the Bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_bitonic(1, array, size);
}

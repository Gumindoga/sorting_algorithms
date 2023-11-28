#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t space, i, j;
	int hold;

	if (array == NULL || size < 2)
		return;

	/* Compute the largest Knuth sequence smaller than size. */
	for (space = 1; space < size; space = space * 3 + 1)
		;

	/* Start with the largest space and work down to a space of 1. */
	for (space = (space - 1) / 3; space > 0; space = (space - 1) / 3)
	{
		/* Do a gapped insertion sort for this space size. */
		for (i = space; i < size; i++)
		{
			/* Save the element at position i and make a hole at position i. */
			hold = array[i];

			/* Shift earlier space-sorted elements up until the correct location for hold is found. */
			for (j = i; j >= space && array[j - space] > hold; j -= space)
				array[j] = array[j - space];

			/* Put hold (the original array[i]) in its correct location. */
			array[j] = hold;
		}

		print_array(array, size);
	}
}

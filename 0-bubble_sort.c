#include "sort.h"

/**
 * swap - swaps two integer values
 * @ap: ptr to integer 1
 * @bp: ptr to integer 2
 */

void swap(int *ap, int *bp)
{
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				swap(&array[b], &array[b + 1]);
				print_array(array, size);
			}
		}
	}
}

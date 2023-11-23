#include "sort.h"

/**
 * swap - swaps two integers
 * @ax: first integer 
 * @bx: second integer
 * returns nothing
 */

void swap(int *ax, int *bx)
{
	int hold = *ax;
	*ax = *bx;
	*bx = hold;
}

/**
 * selection sort - sorts an array of integers
 * using selection sort algorithm
 * @array: array to sort 
 * @size: size of array
 * returns nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, low_bar;

	for (i = 0; i < size - 1; i++)
	{
		low_bar = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[low_bar])
				low_bar = j;

		if (low_bar != i)
		{
			swap(&array[low_bar], &array[i]);
			print_array(array, size);
		}
	}
}

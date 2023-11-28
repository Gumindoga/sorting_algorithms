#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @ax: The first integer to swap.
 * @bx: The second integer to swap.
 */

void swap(int *ax, int *bx)
{
	int hold = *ax;
	*ax = *bx;
	*bx = hold;
}

/**
 * partition - Orders a subset of an array of integers according to
 * the Lomuto scheme.
 * @array: The array of integers.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 * @n: The total size of the array.
 * Return: The final partition index.
 */

int partition(int *array, ssize_t start, ssize_t end, size_t n)
{
	ssize_t middle = start + (end - start) / 2;
	int pivot;
	ssize_t i;
	ssize_t j;

	if (array[start] > array[middle])
		swap(array + start, array + middle);
	if (array[start] > array[end])
		swap(array + start, array + end);
	if (array[middle] > array[end])
		swap(array + middle, array + end);

	pivot = array[middle];

	swap(array + middle, array + end);

	for (i = j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(array + i, array + j);
				print_array(array, n);
			}
			i++;
		}
	}
	if (i != j)
	{
		swap(array + i, array + j);
		print_array(array, n);
	}
	return (i);
}

/**
 * q_sort - Sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: The array of integers.
 * @start: The starting index of the array subset to sort.
 * @end: The ending index of the array subset to sort.
 * @n: The total size of the array.
 */

void q_sort(int *array, ssize_t start, ssize_t end, size_t n)
{
	if (start < end)
	{
		int p = partition(array, start, end, n);

		q_sort(array, start, p - 1, n);
		q_sort(array, p + 1, end, n);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}

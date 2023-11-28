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
 * hoare_scheme - Order a subset of an array of integers according to
 * the Hoare partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int hoare_scheme(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;
	int j = end + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);
		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_recursion - Implement the quicksort algorithm through
 * recursion.
 * @array: An array of integers.
 * @n: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 */

void hoare_recursion(int *array, size_t n, int start, int end)
{
	int pi;

	if (start < end)
	{
		pi = hoare_scheme(array, n, start, end);
		hoare_recursion(array, n, start, pi);
		hoare_recursion(array, n, pi + 1, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_recursion(array, size, 0, size - 1);
}

#include "sort.h"

/**
 * heap_it - turns array into max heap
 * @array: array to heap_it
 * @n: size of the heap
 * @j: root index
 * @total_size: original array size
 */
void heap_it(int *array, size_t n, int j, size_t total_size)
{
	int max = j;
	int lo = 2 * j + 1;
	int hi = 2 * j + 2;

	if (lo < (int)n && array[lo] > array[max])
		max = lo;

	if (hi < (int)n && array[hi] > array[max])
		max = hi;

	if (max != j)
	{
		swap(&array[j], &array[max]);
		print_array(array, total_size);
		heap_it(array, n, max, total_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = size / 2 - 1; j >= 0; j--)
		heap_it(array, size, j, size);

	for (j = size - 1; j >= 0; j--)
	{
		if (j != 0)
		{
			swap(&array[0], &array[j]);
			print_array(array, size);
		}
		heap_it(array, j, 0, size);
	}
}

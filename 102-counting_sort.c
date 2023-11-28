#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int j, end = 0, *n, *new;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < (int)size; j++)
		if (array[j] > end)
			end = array[j];

	n = malloc(sizeof(int) * (end + 1));
	if (n == NULL)
		return;
	for (j = 0; j <= end; j++)
		n[j] = 0;
	for (j = 0; j < (int)size; j++)
		n[array[j]] += 1;
	for (j = 0; j <= end; j++)
		n[j] += n[j - 1];

	print_array(n, end + 1);

	new = malloc(sizeof(int) * size);
	if (new == NULL)
	{
		free(n);
		return;
	}
	for (j = 0; j < (int)size; j++)
	{
		new[n[array[j]] - 1] = array[j];
		n[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = new[j];

	free(n);
	free(new);
}

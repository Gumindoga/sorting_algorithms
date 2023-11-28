#include "sort.h"

/**
 * merge - Merges two sub-arrays of arr[].
 * @array: Array to be sorted
 * @size: Number of elements in @array
 * @lower: lower sub-array
 * @upper: upper sub-array
 */
void merge(int *array, int *lower, int *upper, size_t size)
{
	int i = 0, j = 0, k = 0;
	int l_size = size / 2;
	int u_size = size - l_size;

	printf("Merging...\n");
	printf("[lower]: ");
	print_array(lower, l_size);
	printf("[upper]: ");
	print_array(upper, u_size);
	while (i < l_size && j < u_size)
	{
		if (lower[i] < upper[j])
			array[k++] = lower[i++];
		else
			array[k++] = upper[j++];
	}
	while (i < l_size)
		array[k++] = lower[i++];
	while (j < u_size)
		array[k++] = upper[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int i;
	int centre = size / 2;
	int *lower, *upper;

	if (array == NULL || size < 2)
		return;

	lower = malloc(sizeof(int) * centre);
	upper = malloc(sizeof(int) * (size - centre));
	if (lower == NULL || upper == NULL)
		return;

	for (i = 0; i < centre; i++)
		lower[i] = array[i];
	for (i = centre; i < (int)size; i++)
		upper[i - centre] = array[i];

	merge_sort(lower, centre);
	merge_sort(upper, size - centre);
	merge(array, lower, upper, size);

	free(lower);
	free(upper);
}

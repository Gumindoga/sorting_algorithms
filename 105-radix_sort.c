#include "sort.h"

/**
 * find_max - get the maximum number in an array
 * @array: array to search
 * @size: size of the array
 * Return: the biggest number in the array
 */
int find_max(int *array, size_t size)
{
	int largest = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > largest)
			largest = array[i];
	return (largest);
}

/**
 * csort_radix - counting sort of the array depending on step value
 * @array: array to sort
 * @size: size of the array
 * @step: digit to count
 * Return: nothing
 */
void csort_radix(int *array, size_t size, int step)
{
	int *result = malloc(sizeof(int) * size);
	int n[10] = {0};
	size_t i;

	if (!result)
		return;

	for (i = 0; i < size; i++)
		n[(array[i] / step) % 10]++;

	for (i = 1; i < 10; i++)
		n[i] += n[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		result[n[(array[i] / step) % 10] - 1] = array[i];
		n[(array[i] / step) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = result[i];

	free(result);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int largest = find_max(array, size);
	int step;

	if (!array || size < 2)
		return;

	for (step = 1; largest / step > 0; step *= 10)
	{
		csort_radix(array, size, step);
		print_array(array, size);
	}
}

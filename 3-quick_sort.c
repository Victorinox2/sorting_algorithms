#include "sort.h"

/**
 * swap - swapps two array elements
 * @x: first element
 * @y: second element
 * Return: void
 */

void swap(int *x, int *y)

{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * sort - sorts an array recursively using the quicksort algorithm
 * @array: array to sort
 * @low: array lower bound
 * @high: arrays upper bound
 * @size: size of array
 * Return: nothing
 */

void sort(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low, j;
	int pivot_num = array[high];

	if (low >= high)
		return;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_num)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i],  &array[high]);
		print_array(array, size);
	}
	if (i - low > 1)
		sort(array, low, i - 1, size);
	if (high - i > 1)
		sort(array, i + 1, high, size);
}

/**
 * quick_sort - sorts an array recursively using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	sort(array, 0, size - 1, size);
}

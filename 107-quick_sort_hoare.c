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
 * partition - sorts an array recursively using the quicksort algoritm
 * @array: array to be sorted
 * @low: array lower bound
 * @high: arrays upper bound
 * @size: size of array
 * Return: partition index
 */

int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = high + 1;
	int pivot = array[high];

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * sort - sorts an array recursively using the quicksort algorithm
 * @array: array to be sorted
 * @low: array lower bound
 * @high: arrays upper bound
 * @size: size of array
 * Return: nothing
 */

void sort(int *array, int low, int high, size_t size)
{
	int _partition;

	if (low < high)
	{
		_partition = partition(array, low, high, size);
		sort(array, low, _partition - 1, size);
		sort(array, _partition, high, size);
	}

}

/**
 * quick_sort_hoare - sorts an array recursively using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size)
		return;
	sort(array, 0, size - 1, size);
}

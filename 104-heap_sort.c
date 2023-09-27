#include "sort.h"

/**
 * swap - swppas two array elements
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
 * heapify - the recursive hmax-heap algorithm
 * @array: array to be sorted
 * @size: size of the array
 * @max_indx: array index with largest element
 * Return: nothing
 */

void heapify(int *array, size_t size, int max_indx)
{
	int largest = max_indx;
	int left = 2 * max_indx, right = 2 * max_indx + 1;
	int buf_size = size;

	if (left < buf_size && array[left] > array[largest])
		largest = left;
	if (right < buf_size && array[right] > array[largest])
		largest = right;
	if (largest != max_indx)
	{
		swap(&array[max_indx], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - sorts an array using the sift_down heapsort algorthm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || !size)
		return;
	for (i = size / 2; i >= 0; i--)
	{
		heapify(array, size -i - 1, i);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size - i - 1 , 0);
	}
}

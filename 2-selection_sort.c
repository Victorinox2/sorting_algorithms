include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (!array || size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			array[min_index] ^= array[i];
			array[i] ^= array[min_index];
			array[min_index] ^= array[i];
			print_array(array, size);
		}
	}
}

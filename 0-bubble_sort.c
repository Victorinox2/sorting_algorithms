#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, jeep;

	if (size == 0 || array == NULL)
		return;
	do {
		jeep = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] ^= array[j + 1];
				array[j + 1] ^= array[j];
				array[j] ^= array[j + 1];
				jeep = 1;
				print_array(array, size);
			}
		}
		i++;
	} while (jeep);
}

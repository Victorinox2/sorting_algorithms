#include "sort.h"

/**
 * shell_sort - shell sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int key;

	if (array == NULL || !size)
		return;
	while (gap <= size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			key = array[i];
			j = i;
			while (j > gap - 1 && array[j - gap] >= key)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = key;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

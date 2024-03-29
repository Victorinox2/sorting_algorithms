#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print - prints array
 * @array: array to be printed
 * @left: where to begin from
 * @right: where to stop
 * Return: nothing
 */

void print(int *array, int left, int right)
{
	int i = left;

	for (; i <= right; i++)
	{
		if (i != right)
			printf("%d, ", array[i]);
		else
			printf("%d", array[i]);
	}
	putchar('\n');
}

/**
 * merge - merges 2 arrays
 * @array: arrays to be merged
 * @copy: buffer to  use in the merging
 * @lower: lower bound of the array
 * @mid: middle of the array
 * @higher: array upper bound
 * Return: void
 */

void merge(int *array, int *copy, size_t lower, size_t mid, size_t higher)
{
	size_t left = lower, i = lower;
	size_t right = mid + 1;

	while (left <= mid && right <= higher)
	{
		if (array[left] <= array[right])
			copy[i++] = array[left++];
		else
			copy[i++] = array[right++];
	}
	while (left <= mid)
	{
		copy[i++] = array[left++];
	}
	while (right <= higher)
	{
		copy[i++] = array[right++];
	}
	for (i = lower; i <= higher; i++)
	{
		array[i] = copy[i];
	}
}

/**
 * merge_n_sort - split array into two and merges the array back
 * @array: array to be merged
 * @copy: extra buffer for the merging
 * @lower: lower bound of the array
 * @higher: upper bound of the array
 * Return: nothing
 */
void merge_n_sort(int *array, int *copy, size_t lower, size_t higher)
{
	 size_t mid;

	if (lower == higher)
		return;
	mid = ((lower + higher) / 2);
	if ((higher - lower) % 2 == 0 && mid != 0)
		mid -= 1;
	merge_n_sort(array, copy, lower, mid);
	merge_n_sort(array, copy, mid + 1, higher);
	printf("Merging...\n");
	printf("[left]: ");
	print(array, lower, mid);
	printf("[right]: ");
	print(array, mid + 1, higher);
	merge(array, copy, lower, mid, higher);
	printf("[Done]: ");
	print(array, lower, higher);
}

/**
 * merge_sort - sortes an array using binary search merge sort algorithm
 * @array: array to be merged
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	merge_n_sort(array, temp, 0, size - 1);
	free(temp);
}

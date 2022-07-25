#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *		using bubble sort
 * @array: the unsorted array
 * @size: array size
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swapped = 0;

	if (!array || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
	printf("\n");
}


#include "sort.h"

/**
 * swap - swaps two given elements
 * @x: pointer to first
 * @y: pointer to second
 * Return: nothing
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition - partitions a given array using the Lomuto scheme
 *
 * @array: array to sort
 * @start: first index of the array
 * @end: last index
 * @len: length of the array
 *
 * Return: index of pivot
 */
int partition(int array[],  int start, int end, size_t len)
{
	int pivot = array[end];
	int i, j;

	i = start;
	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, len);
			i++;
		}
	}
	swap(&array[i], &array[end]);
	if (i != j)
		print_array(array, len);

	return (i);
}

/**
 * quicksort_recursion - executes recursive calls to sort the array
 *
 * @array: array to sort
 * @lb: array lower bound
 * @ub: array upper bound
 * @len: array size
 *
 * Return: nothing
 */
void quicksort_recursion(int *array, int lb, int ub, size_t len)
{
	int p_index;

	if (lb < ub)
	{
		p_index = partition(array, lb, ub, len);

		quicksort_recursion(array, lb, p_index - 1, len);
		quicksort_recursion(array, p_index + 1, ub, len);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 *		Quick sort algorithm.
 * @array: the array to sort
 * @size: array length
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1, size);
}

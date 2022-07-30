#include "sort.h"

#define exch(A, B) {\
	int t = A;\
	A = B;\
	B = t;\
}
/**
 * selection - takes an unsorted array of ints and sorts it
 *		by insertion
 * @arr: array
 * @size: array len
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[min] < array[i])
		{
			exch(array[i], array[min]);
			print_array(array, size);
		}
	}
}

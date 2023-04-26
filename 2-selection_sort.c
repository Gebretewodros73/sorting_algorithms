#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - array of integers sorted using selection method
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, midx;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		midx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[midx])
				midx = j;
		}
		if (midx != i)
		{
			tmp = array[midx];
			array[midx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}

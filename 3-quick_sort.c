#include "sort.h"
#include <stdlib.h>

/**
 * lomuto_partition - gives lumto schem partition
 *
 * @array: to be sorted array
 * @lo: lower index
 * @hi: higher index
 * @size: size of array
 *
 * Return: index of the pivot
 */
size_t lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				array[i] ^= array[j];
				array[j] ^= array[i];
				array[i] ^= array[j];
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		array[i + 1] ^= array[hi];
		array[hi] ^= array[i + 1];
		array[i + 1] ^= array[hi];
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_quick_sort - Sort a partition of an array using the Lomuto scheme
 *
 * @array: array to be sorted
 * @lo: lower index
 * @hi: higher index
 * @size: size of array
 */
void lomuto_quick_sort(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, lo, hi, size);

		lomuto_quick_sort(array, lo, p - 1, size);
		lomuto_quick_sort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - Sort using Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_quick_sort(array, 0, size - 1, size);
}

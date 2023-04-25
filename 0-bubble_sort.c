#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sort in assending order using bubble sort method
 *
 * @array: any unsorted array
 * @size: len of an array def sozeof(array)/sizeof(array[0]
 * */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swapped = 1;
	
	if (array == NULL || size < 2)
		return;
	
	for (i = 0; i < size - 1 && swapped; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
					/* print_array(array, size);*/
			}
		}
		/*print_array(array, size);*/
	}
	print_array(array, size);
}

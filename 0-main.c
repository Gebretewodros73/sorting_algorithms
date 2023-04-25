#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {1, 8, 10, 11, 12, 17, 19, 21, 22, 24, 25, 28, 31, 32, 34, 35, 36, 37, 38, 40, 41, 46, 47, 48, 50, 51, 52, 53, 56, 57, 59, 60, 61, 65, 66, 68, 69, 71, 72, 73, 74, 76, 81, 83, 89, 92, 93, 95, 96, 98};
	size_t n = sizeof(array) / sizeof(array[0]);
	time_t start = time(NULL), end = time(NULL);
	double total_time = difftime(end, start);

	printf("%s\n",ctime(&start));
	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	printf("%s\n",ctime(&end));
	printf("\n%fn", total_time);

	return (0);
}

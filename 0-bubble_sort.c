#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using the Bubble Sort
 * algorithm
 * @array: An an array to be sorted
 * @size: size of array to be sorted
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int no_of_swaps;

	for (i = 0; i < size; i++)
	{
		no_of_swaps = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				no_of_swaps = 1;
			}
		}
		if (no_of_swaps == 0)
			break;
	}
}

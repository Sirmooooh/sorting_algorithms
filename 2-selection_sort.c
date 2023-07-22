#include "sort.h"

/**
 * selection_sort - sorts an array following the selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int l, k, min;

	register int temp;

	if (size < 2)
		return;

	for (l = 0; l < size; l++)
	{
		min = l;
		for (k = l + 1; k < size; k++)
		{
			if (array[k] < array[min])
				min = k;
		}
		temp = array[l];
		array[l] = array[min];
		array[min] = temp;
		if (l != min)
			print_array(array, size);
	}
}

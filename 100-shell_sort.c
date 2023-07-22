#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t sort, l, k;

	if (array == NULL || size < 2)
		return;

	for (sort = 1; sort < (size / 3);)
		sort = sort * 3 + 1;

	for (; sort >= 1; sort /= 3)
	{
		for (l = sort; l < size; l++)
		{
			k = l;
			while (k >= sort && array[k - sort] > array[k])
			{
				swap_ints(array + k, array + (k - sort));
				k -= sort;
			}
		}
		print_array(array, size);
	}
}

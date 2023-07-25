#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, l;

	for (max = array[0], l = 1; l < size; l++)
	{
		if (array[l] > max)
			max = array[l];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t l;

	for (l = 0; l < size; l++)
		count[(array[l] / sig) % 10] += 1;

	for (l = 0; l < 10; l++)
		count[l] += count[l - 1];

	for (l = size - 1; (int)l >= 0; l--)
	{
		buff[count[(array[l] / sig) % 10] - 1] = array[l];
		count[(array[l] / sig) % 10] -= 1;
	}

	for (l = 0; l < size; l++)
		array[l] = buff[l];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sort, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	max = get_max(array, size);
	for (sort = 1; max / sort > 0; sort *= 10)
	{
		radix_counting_sort(array, size, sort, buff);
		print_array(array, size);
	}

	free(buff);
}

#include "sort.h"
/**
 * swap_int - swap elements in a list
 *
 * @a: pointer first int
 * @b: pointer second int
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - orders a subset of an array
 *                    of integers in ascending order using the
 *                    lomuto partition scheme (pivot is last element).
 *
 * @array: array to be sorted
 * @size: size of array
 * @left_part: starting index of elements  to the left of pivot
 * @right_part: starting index of elements to the right of pivot
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left_part, int right_part)
{
	int *pivot, top, bottom;

	pivot = array + right_part;
	for (top = bottom = left_part; bottom < right_part; bottom++)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swap_int(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_int(array + top, pivot);
		print_array(array, size);
	}
	return (top);
}

/**
 * lomuto_recur - recursivly calls partion on subarrays
 *
 * @array: array to be sorted
 * @size; size of array
 * @left_part: elements les than pivot
 * @right_part: elements more than pivot
 *
 * Return: void
 */
void lomuto_recur(int *array, size_t size, int left_part, int right_part)
{
	int sub_part;

	if (right_part - left_part > 0)
	{
		sub_part = lomuto_partition(array, size, left_part, right_part);
		lomuto_recur(array, size, left_part, sub_part - 1);
		lomuto_recur(array, size, sub_part + 1, right_part);
	}
}
/**
* quick_sort - sorts an array in ascending order using quick sort
*
* @array: array
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_recur(array, size, 0, size - 1);
}

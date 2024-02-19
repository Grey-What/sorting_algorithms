#include "sort.h"
/**
* quick_sort - sorts an array in ascending order using quick sort
*
* @array: array
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{	
	int pivot, temp;
	size_t i = -1, j;

	if (array == NULL || size < 2)
		return;

	pivot = array[size - 1];
	for (j = 0; j < size; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	
	}
	temp = array[i];
	array[i] = array[size - 1];
	array[size - 1] = temp;

	if (i > 0)
		quick_sort(array, i);
	if (i < size - 1)
		quick_sort(array + i + 1, size - i - 1);
}

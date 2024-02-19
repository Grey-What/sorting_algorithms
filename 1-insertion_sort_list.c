#include "sort.h"
/**
 * insert_swap - swaps two nodes in a doubly linked list
 *
 * @list: head to doubly linked list
 * @n_prev: pointer to previsous node to be swapped
 * @n_cur: pointer to node being evaluated
 *
 * Return: void
 */
void insert_swap(listint_t **list, listint_t **n_prev, listint_t *n_cur)
{
	(*n_prev)->next = n_cur->next;
	if (n_cur->next != NULL)
		n_cur->next->prev = (*n_prev);
	n_cur->prev = (*n_prev)->prev;
	n_cur->next = *n_prev;
	if ((*n_prev)->prev != NULL)
	{
		(*n_prev)->prev->next = n_cur;
	}
	else
		*list = n_cur;
	(*n_prev)->prev = n_cur;
	(*n_prev) = n_cur->prev;
}
/**
 * insertion_sort_list - sorts doubly linked list with insertion sort
 *
 * @list: pointer to list pointer
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur_node, *prev_node, *temp;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	for (cur_node = (*list)->next; cur_node != NULL; cur_node = temp)
	{
		temp = cur_node->next;
		prev_node = cur_node->prev;

		while (prev_node != NULL && cur_node->n < prev_node->n)
		{
			insert_swap(list, &prev_node, cur_node);
			print_list((const listint_t *)*list);
		}
	}
}

#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *hold, *swap;

	if (list == NULL || *list == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		hold = curr;
		swap = curr->prev;
		while (swap != NULL && hold->n < swap->n)
		{
			swap->next = hold->next;
			if (hold->next != NULL)
				hold->next->prev = swap;
			hold->prev = swap->prev;
			if (swap->prev != NULL)
				swap->prev->next = hold;
			else
				*list = hold;
			hold->next = swap;
			swap->prev = hold;
			print_list(*list);
			swap = hold->prev;
		}
		curr = curr->next;
	}
}

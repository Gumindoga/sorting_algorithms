#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	node2->next = node1;
	node1->prev = node2;
}

void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	while (swapped != 0)
	{
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->prev->n > temp->n)
			{
				swap_nodes(list, temp->prev, temp);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	}
}

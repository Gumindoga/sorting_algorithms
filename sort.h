#ifndef _SORT_H_
#define _SORT_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *ap, int *bp);
int partition(int *array, ssize_t start, ssize_t end, size_t n);
void swap(int *ax, int *bx);
bool are_identical(int *array, size_t size);
void q_sort(int *array, ssize_t start, ssize_t end, size_t n);

#endif /* _SORT_H_ */

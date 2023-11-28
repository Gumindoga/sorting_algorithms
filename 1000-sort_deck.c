#include "deck.h"

/**
 * card_face - Get the face of a card.
 * @card: The card to get the value of.
 *
 * Return: The value of the card.
 */
int card_face(const card_t *card)
{
	int j;
	char *faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

	for (j = 0; j < 13; j++)
	{
		if (!strcmp(faces[j], card->value))
			return (j);
	}
	return (0);
}

/**
 * divide - Order a subset of a deck of cards and determine the centre point.
 * @deck: A double pointer to the head of a deck of cards.
 * @lo: The starting node of the subset to order.
 * @hi: The centre node of the subset to order.
 *
 * Return: The centre node of the partitioned subset.
 */

deck_node_t *divide(deck_node_t **deck, deck_node_t *lo, deck_node_t *hi)
{
	deck_node_t *centre, *i, *j;

	centre = hi;
	for (i = j = lo; j != hi; j = j->next)
	{
		if (j->card->kind < centre->card->kind ||
			(j->card->kind == centre->card->kind && card_face(j->card) < card_face(centre->card)))
		{
			if (i != j)
			{
				if (i->prev)
					i->prev->next = j;
				if (j->next)
					j->next->prev = i;
				i->next = j->next;
				j->prev = i->prev;
				i->prev = j;
				j->next = i;
				if (i == *deck)
					*deck = j;
				i = j;
			}
			else
				i = i->next;
		}
	}
	if (i != j)
	{
		if (i->prev)
			i->prev->next = j;
		if (j->next)
			j->next->prev = i;
		i->next = j->next;
		j->prev = i->prev;
		i->prev = j;
		j->next = i;
		if (i == *deck)
			*deck = j;
	}
	return (j);
}

/**
 * qsort_deck - Sort a deck of cards using the quicksort algorithm.
 * @deck: A double pointer to the head of a deck of cards.
 * @lo: The starting node of the subset to order.
 * @hi: The ending node of the subset to order.
 */
void qsort_deck(deck_node_t **deck, deck_node_t *lo, deck_node_t *hi)
{
	deck_node_t *centre;

	if (lo && lo != hi && lo != hi->next)
	{
		centre = divide(deck, lo, hi);
		qsort_deck(deck, lo, centre->prev);
		qsort_deck(deck, centre->next, hi);
	}
}

/**
 * sort_deck - Sort a deck of cards.
 * @deck: A double pointer to the head of a deck of cards.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	for (node = *deck; node->next != NULL; node = node->next)
		;
	qsort_deck(deck, *deck, node);
}

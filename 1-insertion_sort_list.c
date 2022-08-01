#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - swaps two nodes of a linked list
 * @A: first node
 * @B: second node
 * @list: head of linked list
 *
 * Return: void
 */
void swap(listint_t **list, listint_t **A, listint_t **B)
{
	if (!(*B)->next && !(*A)->prev)
	{
		(*B)->prev->next = NULL;

		(*B)->prev = NULL;

		(*B)->next = *A;
		(*A)->prev = *B;

		*list = (*list)->prev;
		print_list(*list);
	}
	else if (!(*A)->prev)
	{
		(*B)->prev->next = (*B)->next;
		(*B)->next->prev = (*B)->prev;

		(*B)->next = *A;
		(*A)->prev = *B;

		(*B)->prev = NULL;

		*list = (*list)->prev;
		print_list(*list);
	}
	else if (!(*B)->next)
	{
		(*B)->prev->next = NULL;
		(*B)->prev = (*A)->prev;
		(*A)->prev->next = *B;

		(*B)->next = *A;
		(*A)->prev = *B;

		print_list(*list);
	}
	else
	{
		(*A)->prev->next = *B;
		(*B)->prev = (*A)->prev;
		(*B)->next->prev = *A;
		(*A)->next = (*B)->next;
		
		(*A)->prev = *B;
		(*B)->next = *A;
		
		print_list(*list);
	}

}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *		ascending order
 *
 * @list: double pointer to doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *rev, *trav;

	trav = (*list)->next;
	while (trav)
	{
		rev = trav->prev;
		while (rev != NULL)
		{
			if (trav->n < rev->n)
				swap(list, &rev, &trav);
			rev = rev->prev;
		}
		trav = trav->next;
	}
}

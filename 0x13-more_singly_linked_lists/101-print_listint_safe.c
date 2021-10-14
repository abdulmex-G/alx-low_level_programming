#include "lists.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

listint_t *find_loop(listint_t *head);

/**
  * print_listint_safe - prints a linked list including those with loops
  * @head: the list
  * Return: number of nodes in the list
  */
size_t print_listint_safe(const listint_t *head)
{
	listint_t *head_hold, *loop;
	int traversed, len;

	head_hold = (listint_t *)head;
	loop = find_loop((listint_t *)head);
	traversed = len =  0;
	while (head_hold)
	{
		printf("%d\n", head_hold->n);
		len++;
		if (head_hold == loop)
		{
			traversed++;
			break;
		}
		head_hold = head_hold->next;
	}

	while (head_hold)
	{
		head_hold = head_hold->next;
		if (head_hold == loop && traversed == 1)
			break;
		printf("%d\n", head_hold->n);
		len++;
	}

	return (len);
}

/**
  * find_loop - checks whether a linked list contains a loop or not
  * @head: head of the loop
  * Return: 1 if there is a loop or 0 if not
  */
listint_t *find_loop(listint_t *head)
{
	listint_t *slow_p, *fast_p;

	slow_p = fast_p = head;
	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			slow_p = head;
			while (slow_p != fast_p)
			{
				slow_p = slow_p->next;
				fast_p = fast_p->next;
			}
			return (fast_p);
		}
	}

	return (NULL);
}
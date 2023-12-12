#include "monty.h"
/**
 * dnodeadd - add node to the beginning of list
 * @head: pointer to first node
 * @n: data inside node
 * Return: pointer to first node
 */
stack_t *dnodeadd(stack_t **head, const int n)
{
	stack_t *new1;

	new1 = malloc(sizeof(stack_t));
	if (new1 == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new1->n = n;
		new1->next = NULL;
		new1->prev = NULL;
		*head = new1;
		return (*head);
	}

	(*head)->prev = new1;
	new1->n = n;
	new1->next = *head;
	new1->prev = NULL;
	*head = new1;
	return (*head);
}
/**
 * endadd - add node to end of list
 * @head: pointer to first node
 * @n: data inside node
 * Return: pointer to first node
 */
stack_t *endadd(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
	return (new);
}
/**
 * fr_ee - free a list
 * @head: pointer to first node
 *
 */
void fr_ee(stack_t *head)
{
	stack_t *tmp;

	for (; head != NULL; )
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

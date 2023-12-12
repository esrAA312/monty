#include "monty.h"
/**
 *ro_tl - rotates the stack to the top
 *@head: stack head
 *@counter: line_number
 *Return: no return
 */
void ro_tl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmpe = *head, *a;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	a = (*head)->next;
	a->prev = NULL;
	while (tmpe->next != NULL)
	{
		tmpe = tmpe->next;
	}
	tmpe->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmpe;
	(*head) = a;
}
/**
 * ro_tr - rotates the list right
 * @head: pointer to the top of the stack
 * @counter: the index of the current line
 *
 */
void ro_tr(stack_t **head, __attribute__((unused)) unsigned int counter);
#include "monty.h"
/**
 *ro_tr- rotates the stack to the bottom
 *@head: stack head
 *@counter: line_number
 *Return: no return
 */
void ro_tr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *cy;

	cy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cy->next)
	{
		cy = cy->next;
	}
	cy->next = *head;
	cy->prev->next = NULL;
	cy->prev = NULL;
	(*head)->prev = cy;
	(*head) = cy;
}

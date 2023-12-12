#include "monty.h"
/**
 * po_p - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 */
void po_p(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		err(stack);
	}
	dnodedel(stack, 0);
}
/**
 * _nop - literally does nothing
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * dnodedel - delete node a specific spot
 * @head: pointer to first node on list
 * @index: position to delete
 * Return: 1 if successful, -1 if failure
 */
int dnodedel(stack_t **head, unsigned int index)
{
	stack_t *tmpe1;
	stack_t *tmpe2;
	unsigned int x;

	if (*head == NULL)
		return (-1);

	tmpe1 = *head;

	if (index == 0)
	{
		*head = tmpe1->next;
		if (tmpe1->next != NULL)
			tmpe1->next->prev = NULL;
		free(tmpe1);
		return (1);
	}
	for (x = 0; x < (index - 1); x++)
	{
		if (tmpe1 == NULL)
			return (-1);
		tmpe1 = tmpe1->next;
	}
	tmpe2 = (tmpe1->next)->next;
	if (tmpe1->next->next != NULL)
		tmpe1->next->next->prev = tmpe1;
	free(tmpe1->next);
	tmpe1->next = tmpe2;

	return (1);
}

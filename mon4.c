#include "monty.h"

/**
 * mu_l - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void mu_l(stack_t **stack, unsigned int mon)
{
	int mul;

	if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
		e1(8, mon, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * sw_ap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void sw_ap(stack_t **stack, unsigned int mon)
{        stack_t *run;
	int tmpe;

	run = *stack;
	if (run == NULL || run->next == NULL)
	{
		e2(8, mon, "swap");	}
	tmpe = run->n;
	run->n = run->next->n;
	run->next->n = tmpe;
}
/**
 * po_p - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void po_p(stack_t **stack, unsigned int mon)
{
	if (stack == NULL || *stack == NULL)
	{
		e2(7, mon);
	}
	dnodedel(stack, 0);
}


/**
 *dnodedel - delete node a specific spot
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
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

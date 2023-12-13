#include "monty.h"

/**
 * ro_tl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lnx: Interger representing the line number of of the opcode.
 */
void ro_tl(stack_t **stack, __attribute__((unused))unsigned int lnx)
{
	stack_t *tmpe;

	if (stack == NULL || (*stack)->next == NULL)
		return;

	tmpe = *stack;
	while (tmpe->next != NULL)
		tmpe = tmpe->next;

	tmpe->next = *stack;
	(*stack)->prev = tmpe;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

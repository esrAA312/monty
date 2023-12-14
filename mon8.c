#include "monty.h"
/**
 * prints - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: line number of  the opcode.
 */
void prints(stack_t **stack, __attribute__ ((unused))unsigned int mon)
{
	stack_t *tmpe;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmpe = *stack;
	for (; tmpe != NULL;)
	{
		printf("%d\n", tmpe->n);
		tmpe = tmpe->next;
	}
}
/**
 * e3 - handles errors.
 * @cerr: The error codes are the following code
 */
void e3(int cerr, ...)
{
	va_list ag;
	int nu;

	va_start(ag, cerr);
	nu = va_arg(ag, int);
	if (cerr == 10)
	{
		nu = va_arg(ag, int);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nu);
	}
	else if (cerr == 11)
	{
		nu = va_arg(ag, int);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nu);
	}
	va_end(ag);
	free_nodes();
	exit(EXIT_FAILURE);
}

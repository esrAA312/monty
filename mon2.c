#include "monty.h"

/**
 * strp - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lnx: Interger representing the line number of of the opcode.
 */
void strp(stack_t **stack, __attribute__((unused))unsigned int lnx)
{
	int ascii;
	stack_t *tmpe;

		if (*stack == NULL)
		{
			printf("\n");
			return;
		}

	tmpe = *stack;
	while (tmpe != NULL)
	{
		ascii = tmpe->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmpe = tmpe->next;

	}
	printf("\n");
}

/**
 *ro_tr - rotates the stack to the bottom
 *@he: stack head
 *@Inx: line_number
 *Return: no return
 */
void ro_tr(stack_t **he, __attribute__((unused)) unsigned int Inx)
{
	stack_t *cop;

	cop = *he;
	if (*he == NULL || (*he)->next == NULL || he == NULL)
	{
		return;
	}
	while (cop->next)
	{
		cop = cop->next;
	}
	cop->next = *he;
	cop->prev->next = NULL;
	cop->prev = NULL;
	(*he)->prev = cop;
	(*he) = cop;
}

/**
 * di_v - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void di_v(stack_t **stack, unsigned int mon)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		e2(8, mon, "div");

	if ((*stack)->n == 0)
		e2(9, mon);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * e2 - handles errors.
 * @cerr: The error codes are the following:
 */
void e2(int cerr, ...)
{
	va_list ag;
	char *p;
	int nu;

	va_start(ag, cerr);
	if (cerr == 6)
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
	else if (cerr == 7)
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
	else if (cerr == 8)
	{	nu = va_arg(ag, unsigned int);
		p = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", nu, p);
	}
	else if (cerr == 9)
		fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
	va_end(ag);
	free_nodes();
	exit(EXIT_FAILURE);
}

#include "monty.h"


/**
 * add_st - Adds a node to the stack.
 * @stack: Pointer to the new node.
 * @lnx: Interger representing the line number of of the opcode.
 */
void add_st(stack_t **stack, __attribute__((unused))unsigned int lnx)
{
	stack_t *tmpe;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *stack;
		return;
	}
	tmpe = head;
	head = *stack;
	head->next = tmpe;
	tmpe->prev = head;
}

/**
 * e1 - Prints appropiate error messages determined by their error code.
 * @cerr: The error codes are the following:
 */
void e1(int cerr, ...)
{
	va_list ag;
	char *p;
	int nu;

	va_start(ag, cerr);

	if (cerr == 1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (cerr == 2)
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
	else if (cerr == 3)
	{
		nu = va_arg(ag, int);
		p = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", nu, p);
	}
	else if (cerr == 4)
		fprintf(stderr, "Error: malloc failed\n");
	else if (cerr == 5)
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));

	va_end(ag);
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * pin_t - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void pin_t(stack_t **stack, unsigned int mon)
{
	stack_t *run;

	run = *stack;
	if (stack == NULL || *stack == NULL)
		e2(6, mon);
	printf("%d\n", run->n);
}

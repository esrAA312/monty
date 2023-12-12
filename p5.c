#include "monty.h"
/**
 * ps_tr - print string starting a top of stack
 * @stack: linked list for stack
 * @line: line number opcode occurs on
 */
void ps_tr(stack_t **stack, __attribute__ ((unused))unsigned int line)
{
	stack_t *run;
	int v;

	run = *stack;

	for (; run != NULL;)
	{
		v = run->n;
		if (v == 0)
			break;
		if (!isprint(v))
		{
			break;
		}
		_putchar(v);
		run = run->next;
	}
	_putchar('\n');
}
/**
 * sta_ck - sets sq_flag to stack
 * @stack: pointer to stack list
 * @line: line opcode occurs on
 */
void sta_ck(__attribute__ ((unused)) stack_t **stack,
		__attribute__ ((unused)) unsigned int line)
{
	glo = 0;
}
/**
 * que_ue - sets sq_flag to queue
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void que_ue(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
	glo = 1;
}

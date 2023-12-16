#include "monty.h"

/**
 * no_p - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void no_p(stack_t **stack, unsigned int mon)
{
	(void)stack;
	(void)mon;
}
/**
 * ad_d - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void ad_d(stack_t **stack, unsigned int mon)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		e2(8, mon, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * pl - Separates each line into tokens
 * @buf: line from the file
 * @mon: line number
 * @format:   If 0 Nodes will be entered as a stack.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int pl(char *buf, int mon, int format)
{
	char *code, *val;
	const char *delimt = "\n ";

	if (buf == NULL)
		e1(4);

	code = strtok(buf, delimt);
	if (code == NULL)
		return (format);
	val = strtok(NULL, delimt);

	if (_strcmp(code, "stack") == 0)
	if (_strcmp(code, "queue") == 0)
			return (1);

	f_func(code, val, mon, format);
	return (format);
}

#include "monty.h"

/**
 * pch_ar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void pch_ar(stack_t **stack, unsigned int line_number)
{
	stack_t *run;
	int v;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pcar, stack empty\n", line_number);
		string_err(11, line_number);
	}

	run = *stack;
	v = run->n;

	if (!isprint(v))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		string_err(10, line_number);
	}

	putchar(v);
	putchar('\n');
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 *f_rotr- rotates the stack to the bottom
 *@he: stack head
 *@counter: line_number
 *Return: no return
 */
void f_rotr(stack_t **he, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *he;
	if (*he == NULL || (*he)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *he;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*he)->prev = copy;
	(*he) = copy;
}

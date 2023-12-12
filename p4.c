#include "monty.h"

/**
 * pch_ar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line: the index of the current line
 *
 */
void pch_ar(stack_t **stack, unsigned int line)
{
	stack_t *run;
	int v;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		err(stack);
	}

	run = *stack;
	v = run->n;

	if (!isprint(v))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		err(stack);
	}

	_putchar(v);
	_putchar('\n');
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

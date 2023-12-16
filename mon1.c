#include "monty.h"

/**
 * pch_ar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @mon: the index of the current line
 *
 */
void pch_ar(stack_t **stack, unsigned int mon)
{
	stack_t *run;
	int v;

	if (*stack == NULL || stack == NULL)
	{
		e3(11, mon);
	}

	run = *stack;
	v = run->n;

	if (!isprint(v))
	{
		e3(10, mon);
	}

	_putchar(v);
	_putchar('\n');
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * mo_d - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void mo_d(stack_t **stack, unsigned int mon)
{
	int mod;

	if (stack == NULL || (*stack)->next == NULL || stack == NULL)

		e2(8, mon, "mod");


	if ((*stack)->n == 0)
		e2(9, mon);
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

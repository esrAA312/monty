#include "monty.h"

/**
 * strp - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lnx: Interger representing the line number of of the opcode.
 */
void strp(stack_t **stack, __attribute__((unused))unsigned int lnx)
{
	int ascii;
	stack_t *tmpe

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
	if (*he == NULL || (*he)->next == NULL)
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

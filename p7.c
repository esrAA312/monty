#include "monty.h"
/**
 * addint - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 */
void addint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		err(stack);
	}
	(*stack)->next->n += (*stack)->n;
	po_p(stack, line);
}

/**
 * subint - subtracts top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 */
void subint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		err(stack);
	}
	(*stack)->next->n -= (*stack)->n;
	po_p(stack, line);
}

/**
 * mulint - multiply top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 *
 */
void mulint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		err(stack);
	}
	(*stack)->next->n *= (*stack)->n;
	po_p(stack, line);
}

/**
 * divint - divide top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 */
void divint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		err(stack);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		err(stack);
	}
	(*stack)->next->n /= (*stack)->n;
	po_p(stack, line);
}

/**
 * modint - mod top of stack and second top of stack
 * * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 *
 */
void modint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		err(stack);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		err(stack);
	}
	(*stack)->next->n %= (*stack)->n;
	po_p(stack, line);
}

nclude "monty.h"
/**
 * p_int - print int a top of stack
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 *
 */
void p_int(stack_t **stack, unsigned int line)
{
	stack_t *run;

	run = *stack;
	if (run == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		err(stack);
	}
	printf("%d\n", run->n);
}
/**
 * sw_ap - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 *
 */
void sw_ap(stack_t **stack, unsigned int line)
{
	stack_t *run;
	int tmpe;

	run = *stack;
	if (run == NULL || run->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		err(stack);
	}
	tmpe = run->n;
	run->n = run->next->n;
	run->next->n = tmpe;
}
/**
 * err - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void err(stack_t **stack)
{
	if (*stack)
		fr_ee(*stack);
	exit(EXIT_FAILURE);
}

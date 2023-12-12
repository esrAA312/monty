#include "monty.h"
/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line)
{
	char *c;

	c = strtok(line, "\n ");
	if (c == NULL)
		return (NULL);
	return (c);
}
/**
 * p_all - print all function
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 */
void p_all(stack_t **stack, __attribute__ ((unused))unsigned int line)
{
	stack_t *run;

	run = *stack;
	for (; run != NULL;)
	{
		printf("%d\n", run->n);
		run = run->next;
	}
}

#include "monty.h"
/**
 * pu_sh - push int to a stack
 * @stack: linked lists for monty stack
 * @line: number of line opcode occurs on
 */
void pu_sh(stack_t **stack, unsigned int line)
{
	stack_t *new;
	char *arg;
	int p_arg;

	p_arg = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		write(1, "Error: malloc failed\n", 21);
		err(stack);
	}

	arg = strtok(NULL, "\n ");
	if (itnum(arg) == 1 && arg != NULL)
	{
		p_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		err(stack);
	}

	if (glo == 1)
	{
		endadd(stack, p_arg);
	}

	if (glo == 0)
	{
		dnodeadd(stack, p_arg);
	}
}

/**
 * itnum - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int itnum(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

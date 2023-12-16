#include "monty.h"

/**
 * ofile - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void ofile(char *file_name)
{
	FILE *ptrr = fopen(file_name, "r");

	if (file_name == NULL || ptrr == NULL)
		e1(2, file_name);

	rfile(ptrr);
	fclose(ptrr);
}


/**
 * rfile - reads a file
 * @d: pointer to file descriptor
 * Return: void
 */

void rfile(FILE *d)
{
	int mon, format = 0;
	char *buf = NULL;
	size_t l = 0;

	mon = 1;

	while (getline(&buf, &l, d) != -1)
	{
		format = pl(buf, mon, format);
		mon++;
	}
	free(buf);
}
/**
 * add_qu - Adds a node to the queue.
 * @stack: Pointer to the new node.
 * @lnx: line number of the opcode.
 */
void add_qu(stack_t **stack, __attribute__((unused))unsigned int lnx)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *stack;
		return;
	}
	x = head;
	for (; x->next != NULL;)
		x = x->next;

	x->next = *stack;
	(*stack)->prev = x;

}
/**
 * cfun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @o: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @j: Format specifier. If 0 Nodes will be entered as a stack.
 */
void cfun(op_func func, char *o, char *val, int ln, int j)
{
	stack_t *x;
	int fg;
	int i;

	fg = 1;
	if (_strcmp(o, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fg = -1;
		}
		if (val == NULL)
			e1(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				e1(5, ln);
		}
		x = cnode(atoi(val) * fg);
		if (j == 0)
			func(&x, ln);
		if (j == 1)
			add_qu(&x, ln);
	}
	else
		func(&x, ln);
}

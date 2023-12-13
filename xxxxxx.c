#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);

	if (error_code == 1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (error_code == 2)
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
	else if (error_code == 3)
	{
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
	}
	else if (error_code == 4)
		fprintf(stderr, "Error: malloc failed\n");
	else if (error_code == 5)
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));

	va_end(ag);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	if (error_code == 6)
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
	else if (error_code == 7)
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
	else if (error_code == 8)
	{	l_num = va_arg(ag, unsigned int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
	}
	else if (error_code == 9)
		fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
	va_end(ag);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following code
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	if (error_code == 10)
	{
		l_num = va_arg(ag, int);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
	}
	else if (error_code == 11)
	{
		l_num = va_arg(ag, int);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
	}
	va_end(ag);
	free_nodes();
	exit(EXIT_FAILURE);
}

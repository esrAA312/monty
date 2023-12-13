#include "monty.h"
/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 *Every good language comes with the capability of commenting.
 */
int glo = NULL;
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		write(1, "USAGE: monty file\n", 18);
		err(&stack);
	}
	read_f(av[1], &stack);
	fr_ee(stack);
	return (0);
}

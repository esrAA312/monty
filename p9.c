#include "monty.h"
/**
 * read_f - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 *
 */
void read_f(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *l;
	size_t i = 0;
	int coun = 1;
	instruct_func s;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		err(stack);
	}
	for (; (read = getline(&buffer, &i, file)) != -1; )
	{
		l = parse_line(buffer);
		if (l == NULL || l[0] == '#')
		{
			coun++;
			continue;
		}
		s = op(l);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", coun, l);
			err(stack);
		}
		s(stack, coun);
		coun++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
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

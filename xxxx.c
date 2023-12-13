#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: line number of  the opcode.
 */
void print_stack(stack_t **stack, __attribute__ ((unused))unsigned int line)
{
	stack_t *tmp;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	for (; tmp != NULL;)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		more_err(7, line_number);
	}
	dnodedel(stack, 0);
}


/**
 *dnodedel - delete node a specific spot
 * @head: pointer to first node on list
 * @index: position to delete
 * Return: 1 if successful, -1 if failure
 */
int dnodedel(stack_t **head, unsigned int index)
{
	stack_t *tmpe1;
	stack_t *tmpe2;
	unsigned int x;

	if (*head == NULL)
		return (-1);

	tmpe1 = *head;

	if (index == 0)
	{
		*head = tmpe1->next;
		if (tmpe1->next != NULL)
			tmpe1->next->prev = NULL;
		free(tmpe1);
		return (1);
	}
	for (x = 0; x < (index - 1); x++)
	{
		if (tmpe1 == NULL)
			return (-1);
		tmpe1 = tmpe1->next;
	}
	tmpe2 = (tmpe1->next)->next;
	if (tmpe1->next->next != NULL)
		tmpe1->next->next->prev = tmpe1;
	free(tmpe1->next);
	tmpe1->next = tmpe2;

	return (1);
}
/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	stack_t *run;

	run = *stack;
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", run->n);
}

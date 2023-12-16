#include "monty.h"

/**
 * ro_tl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lnx: Interger representing the line number of of the opcode.
 */
void ro_tl(stack_t **stack, __attribute__((unused))unsigned int lnx)
{
	stack_t *tmpe;

	if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
		return;

	tmpe = *stack;
	while (tmpe->next != NULL)
		tmpe = tmpe->next;

	tmpe->next = *stack;
	(*stack)->prev = tmpe;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * su_b - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @mon: Interger representing the line number of of the opcode.
 */
void su_b(stack_t **stack, unsigned int mon)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		e2(8, mon, "sub");


	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * cnode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *cnode(int n)
{
	stack_t *x;

	x = malloc(sizeof(stack_t));
	if (x == NULL)
		e1(4);
	x->next = NULL;
	x->prev = NULL;
	x->n = n;
	return (x);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *x;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		x = head;
		head = head->next;
		free(x);
	}
}
/**
 * f_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @form:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * Return: void
 */
void f_func(char *opcode, char *val, int ln, int form)
{
	int i;
	int fg;

	instruction_t func_list[] = {
		{"push", add_st},
		{"pall", prints},
		{"pint", pin_t},
		{"pop", po_p},
		{"nop", no_p},
		{"swap", sw_ap},
		{"add", ad_d},
		{"sub", su_b},
		{"div", di_v},
		{"mul", mu_l},
		{"mod", mo_d},
		{"pchar", pch_ar},
		{"pstr", strp},
		{"rotl", ro_tl},
		{"rotr", ro_tr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fg = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (_strcmp(opcode, func_list[i].opcode) == 0)
		{
			cfun(func_list[i].f, opcode, val, ln, form);
			fg = 0;
		}
	}
	if (fg == 1)
		e1(3, ln, opcode);
}

#include "monty.h"
/**
 * op -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func op(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", pu_sh},
		{"pall", p_all},
		{"pint", p_int},
		{"pop", po_p},
		{"swap", sw_ap},
		{"pchar", pch_ar},
		{"add", addint},
		{"sub", subint},
		{"mul", mulint},
		{"div", divint},
		{"mod", modint},
		{"nop", _nop},
		{"rotl", ro_tl},
		{"rotr", ro_tr},
		{"pstr", ps_tr},
		{"stack", sta_ck},
		{"queue", que_ue},
		{NULL, NULL},
	};
	i = 0;
	while (instruct[i].f != NULL && _strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

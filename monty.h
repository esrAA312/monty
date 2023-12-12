#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int glo;
/*--- Struct Definitions ---*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line);
} instruction_t;

typedef void (*instruct_func)(stack_t **stack, unsigned int line);
char *parse_line(char *line);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
instruct_func op(char *str);
void read_f(char *filename, stack_t **stack);
void p_all(stack_t **stack, unsigned int line);
void sw_ap(stack_t **stack, unsigned int line);
void _nop(stack_t **stack, unsigned int line_number);
void pch_ar(stack_t **stack, unsigned int line);
void p_int(stack_t **stack, unsigned int line);
void pu_sh(stack_t **stack, unsigned int line);
void po_p(stack_t **stack, unsigned int line);
void addint(stack_t **stack, unsigned int line);
void subint(stack_t **stack, unsigned int line);
void mulint(stack_t **stack, unsigned int line);
void divint(stack_t **stack, unsigned int line);
void ps_tr(stack_t **stack, unsigned int line);
void modint(stack_t **stack, unsigned int line);
void ro_tl(stack_t **stack, unsigned int line);
void ro_tr(stack_t **head, unsigned int counter);
void que_ue(stack_t **stack, unsigned int line);
void sta_ck(stack_t **stack, unsigned int line);
stack_t *endadd(stack_t **head, const int n);
stack_t *dnodeadd(stack_t **head, const int n);
void fr_ee(stack_t *head);
int dnodedel(stack_t **head, unsigned int index);
void err(stack_t **stack);
int itnum(char *str);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void ro_tl(stack_t **head,  __attribute__((unused)) unsigned int counter);
#endif

#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void ofile(char *file_name);
int pl(char *buf, int mon, int format);
void rfile(FILE *);
int len_chars(FILE *);
void f_func(char *, char *, int, int);
void pch_ar(stack_t **stack, unsigned int mon);
void ro_tr(stack_t **head, __attribute__((unused)) unsigned int Inx);
stack_t *cnode(int n);
void free_nodes(void);
void prints(stack_t **stack, __attribute__ ((unused))unsigned int mon);
void add_st(stack_t **, unsigned int);
void add_qu(stack_t **, unsigned int);
void cfun(op_func, char *, char *, int, int);
void pin_t(stack_t **, unsigned int);
void po_p(stack_t **, unsigned int);
void no_p(stack_t **, unsigned int);
void sw_ap(stack_t **, unsigned int);
void ad_d(stack_t **, unsigned int);
void su_b(stack_t **, unsigned int);
void di_v(stack_t **, unsigned int);
void mu_l(stack_t **, unsigned int);
void mo_d(stack_t **, unsigned int);
void pch_ar(stack_t **, unsigned int);
void strp(stack_t **, unsigned int);
void ro_tl(stack_t **, unsigned int);
void e1(int error_code, ...);
void e2(int error_code, ...);
void e3(int error_code, ...);
int dnodedel(stack_t **head, unsigned int index);
void ro_tr(stack_t **, unsigned int);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
#endif

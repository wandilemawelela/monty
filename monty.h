#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

extern void execute_opcode(const char *opcode,
		stack_t **stack, unsigned int line_number);
extern void push(stack_t **stack,
		const char *opcode, unsigned int line_number);
extern void pall(stack_t **stack, unsigned int line_number);
extern void pint(stack_t **stack, unsigned int line_number);
extern void pop(stack_t **stack, unsigned int line_number);
extern void swap(stack_t **stack, unsigned int line_number);
extern void add(stack_t **stack, unsigned int line_number);
extern void nop(stack_t **stack, unsigned int line_number);
extern void sub(stack_t **stack, unsigned int line_number);
extern void div_op(stack_t **stack, unsigned int line_number);
extern void mul(stack_t **stack, unsigned int line_number);
extern void mod(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

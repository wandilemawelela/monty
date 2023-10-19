#include "monty.h"

/**
 * push_wrapper - wrapper function
 * @stack: Stack structure
 * @line_number: Literally a line number
 *
 * Return: Nothing
 *
 */

void push_wrapper(stack_t **stack, unsigned int line_number)
{
	push(stack, strtok(NULL, " \t\n"), line_number);
}

/**
 * execute_opcode - Calls different functions to execute their opcode
 * @opcode: Opcode charactor
 * @stack: Pointer to stack structure
 * @line_number: Literally a line number
 *
 * Return: Nothing
 *
 */

void execute_opcode(const char *opcode, stack_t **stack,
		unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push_wrapper},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

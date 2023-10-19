#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @stack: Literally a stack
 * @line_number: Literally a line number
 *
 * Return: Nothing
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't perform nop, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	(void)stack;
	(void)line_number;
}

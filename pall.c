#include "monty.h"

/**
 * pall - Prints from stack
 * @stack: Stack structure
 * @line_number: Literally a line number
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("Stack is empty.\n");
		return;
	}

	while (current != NULL)
	{
		printf("%ld\n", (long int)current->n);
		current = current->next;
	}
}

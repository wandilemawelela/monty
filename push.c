#include "monty.h"

/**
 * push - Pushes the opcode to the stack. I hope this description
 * is short
 * @stack: Stack structure
 * @value: Value to push to the stack
 * @line_number: Literally a line number
 *
 * Description: This function pushes a new node with the given value onto the
 * stack. If the stack is empty, it creates a new stack. The new
 * node becomes the head of the stack.
 *
 * Return: Nothing
 *
 */

void push(stack_t **stack, const char *value, unsigned int line_number)
{
	int num;
	stack_t *new_node;

	if (value == NULL || !isdigit(*value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(value);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}

	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}

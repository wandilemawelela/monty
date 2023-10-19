#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 *
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;

	/* Checks the number of args passed to main */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* If the number of args are matched, open the bytecode file in read-only */
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Reading file line by line */
	while (getline(&line, &len, file) != -1)
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#' && strcmp(opcode, "") != 0)
		{
			execute_opcode(opcode, &stack, line_number);
		}
		line_number++;
	}

	fclose(file);
	free(line);

	return (0);
}

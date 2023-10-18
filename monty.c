#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	char *line = NULL; /* line buffer for holding each line read from the file */
	size_t len = 0; /* Lenght of the line buffer */
	unsigned int line_number = 1; /* Current line number */

	/* Checks the number of args passed to main */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* If the number of args are matched, open the bytecode file in read-only */
	
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Reading file line by line */
	while (getline(&line, &len, file) != -1)
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
		{
			execute_opcode(opcode);
		}
		line_number++;
	}

	fclose(file);
	free(line);

	return (0);
}

#include "monty.h"

/**
 * execute - execute a monty command
 * @line: the command
 * @file: the file
 * @stack: the stack
 * @line_number: the line number
 * Return: 0, 1 if error
 */
int execute(char *line, FILE *file, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *op;
	instruction_t opst[] = {
		{"push", _push}, {"pall", _pall}, {NULL, NULL}
	};

	op = strtok(line, " \n\t");
	if (!op)
		return (1);
	if (op[0] == '#')
		return (0);
	bus.args = strtok(NULL, " \n\t");
	while (opst[i].opcode)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "cmd not found");
	fclose(file);
	free(line);
	exit(EXIT_FAILURE);
}


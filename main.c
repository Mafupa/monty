#include "monty.h"
bus_t bus = {NULL, NULL, NULL};

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	size_t size = 0;
	int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		exit(EXIT_FAILURE);
	bus.file = fopen(argv[1], "r");
	if (!bus.file)
		exit(EXIT_FAILURE);
	while (getline(&(bus.line), &size, bus.file))
	{
		execute(bus.line, bus.file, &stack, line_number);
		line_number++;
		free(bus.line);
	}
	fclose(bus.file);

	return (0);
}

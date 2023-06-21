#include "monty.h"

glob_t global;

/**
 * main - the main func
 * @argc: num of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success else failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	exe(&stack);
	fclose(global.file);
	free(global.line);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}

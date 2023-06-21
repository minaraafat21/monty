#include "monty.h"

/**
 * exe - reads and executes opcodes from a file
 * @stack: pointer top element of stack
 */
void exe(stack_t **stack)
{
	char *monty_command = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int lineNUm = 0;

	while ((nread = getline(&global.line, &len, global.file)) != -1)
	{
		lineNUm++;
		monty_command = strtok(global.line, " \t\r\n\a");
		global.arg = strtok(NULL, " \n\t");
		if (monty_command == NULL || *monty_command == '#')
			continue;
		execute_opcode(monty_command, stack, lineNUm);
	}
}

/**
 * execute_opcode - executes a single opcode
 * @opcode: opcode to execute
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", myPush},
		{"pall", myPall},
		{"pint", myPint},
		{"pop", myPop},
		{"swap", mySwap},
		/*{"nop", op_nop},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},*/
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(global.file);
	free(global.line);
	exit(EXIT_FAILURE);
}

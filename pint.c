#include "monty.h"

/**
 * myPint - prints the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
*/
void myPint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(global.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

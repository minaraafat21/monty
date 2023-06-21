#include "monty.h"

/**
 * myPint -  prints the value at the top of the stack, followed by a new line.
 * @custom_stack: pointer to the top element
 * @custom_line_number: line number of the opcode
*/
void myPint(stack_t **custom_stack, unsigned int custom_line_number)
{
	if (*custom_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", custom_line_number);
		free(global.line);
		loop_free(*custom_stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*custom_stack)->n);
}

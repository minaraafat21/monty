#include "monty.h"

/**
 * myPop - removes element on top of the stack
 * @stack: pointer to top
 * @line_number: line number of the opcode
 **/
void myPop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(global.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack != NULL)
		(*stack)->prev = NULL;
}

#include "monty.h"

/**
 * myAdd - adds first two of stack elements
 * @stack: pointer top
 * @line_number: line number of the opcode
 **/
void myAdd(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global.line);
		loop_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	myPop(stack, line_number);
}

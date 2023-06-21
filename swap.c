#include "monty.h"

/**
 * mySwap - swaps the first 2 elements
 * @stack: pointer to top
 * @line_number: line number of the opcode
*/
void mySwap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(global.line);
		loop_free(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)

	temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

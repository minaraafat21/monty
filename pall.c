#include "monty.h"

/**
 * myPall - prints all values on the stack
 * @stack: pointer to top
 * @line_number: line number of the opcode
 */
void myPall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		(void)line_number;
	}

}

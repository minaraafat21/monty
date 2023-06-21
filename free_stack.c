#include "monty.h"

/**
 * loop_free - frees a stack_t list
 * @stack: pointer to the top of the stack
 */
void loop_free(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

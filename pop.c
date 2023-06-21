#include "monty.h"

/**
 * myPop - removes the top element of the stack
 * @customStack: pointer to the top of the stack
 * @lineNum: line number of the opcode
 */
void myPop(stack_t **customStack, unsigned int lineNum)
{
	stack_t *tempStack;

	if (*customStack == NULL)
	{
		fprintf(stderr, "L%d: unable to pop from an empty stack\n", lineNum);
		free(global.line);
		loop_free(*customStack);
		exit(EXIT_FAILURE);
	}

	tempStack = (*customStack)->next;
	free(*customStack);
	*customStack = tempStack;
	if (*customStack != NULL)
		(*customStack)->prev = NULL;
}

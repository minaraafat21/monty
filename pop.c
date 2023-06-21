#include "monty.h"

/**
 * myPop - pops
 * @customStack: pointer to top
 * @customLineNum: line number of the opcode
 **/
void myPop(stack_t **customStack, unsigned int customLineNum)
{
	stack_t *tempNode;

	if (*customStack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", customLineNum);
		free(global.line);
		loop_free(*customStack);
		exit(EXIT_FAILURE);
	}

	tempNode = (*customStack)->next;
	free(*customStack);
	*customStack = tempNode;
	if (*customStack != NULL)
		(*customStack)->prev = NULL;
}

#include "monty.h"

/**
 * mySwap - swaps the first 2 elements
 * @customStack: pointer to top
 * @customLineNum: line number of the opcode
*/
void mySwap(stack_t **customStack, unsigned int customLineNum)
{
	stack_t *tempNode;

	if (*customStack == NULL || (*customStack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", customLineNum);
		free(global.line);
		loop_free(*customStack);
		exit(EXIT_FAILURE);
	}

	tempNode = (*customStack)->next;
	(*customStack)->next = tempNode->next;

	if (tempNode->next != NULL)
		tempNode->next->prev = *customStack;

	tempNode->prev = NULL;
	tempNode->next = *customStack;
	(*customStack)->prev = tempNode;
	*customStack = tempNode;
}

#include "monty.h"

/**
 * myPush - pushes an element onto the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number of the opcode in the Monty file
 */
void myPush(stack_t **stack, unsigned int line_number)
{
	int n;

	if (global.arg == NULL || !is_num(global.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		loop_free(*stack);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	n = atoi(global.arg);
	if (add_node(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		loop_free(*stack);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_num - check if string is a num
 * @str: string
 *
 * Return: 1 if string is a number else 0 on failure
 */
int is_num(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
/**
 * myPall - prints all values on the stack
 * @stack: pointer to top
 * @line_number: line number of the opcode
 */
void myPall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	for (; current != NULL; current = current->next)
	{
		printf("%d\n", current->n);
		(void)line_number;
	}

}

#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	FILE *file;
	char *line;
	char *arg;

} glob_t;

extern glob_t global;

void exe(stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);

void myPush(stack_t **stack, unsigned int line_number);
void myPall(stack_t **stack, unsigned int line_number);
void myPint(stack_t **stack, unsigned int line_number);
void myPop(stack_t **stack, unsigned int line_number);
void mySwap(stack_t **stack, unsigned int line_number);
void myAdd(stack_t **stack, unsigned int line_number);
void myNop(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **stack, const int n);
int is_num(char *str);
void loop_free(stack_t *stack);

#endif

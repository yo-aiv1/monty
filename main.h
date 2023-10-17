#ifndef _MAIN_h_
#define _MAIN_h_

#define  _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: opcode hundler
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - opcoode helper
 * @op_name: the opcode
 * @value: opcode value
 * @head: node's head
 */

typedef struct global_s
{
	char *op_name;
	char *value;
	stack_t *head;
} global_t;

extern global_t global;


void function_hundler(stack_t **stack, unsigned int line_number);
void free_stack(void);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);


#endif

#include "monty.h"
#include <string.h>
/**
 * _stac - push a node on top of stack
 * @stack: doubly linked list
 */
void _stac(stack_t **stack)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(global.value);
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
	global.head = new;
}

/**
 * _queu - push a node on top queue
 * @stack: doubly linked list
 */
void _queu(stack_t **stack)
{
	stack_t *new = NULL, *tmp = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	new->prev = tmp;
}
/**
 * _push - push a node on top
 * @stack: doubly linked list
 * @line_number: line's num in morty script
 */

void _push(stack_t **stack, unsigned int line_number)
{
	unsigned int size = 0;
	int number = 0;

	if (global.value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	size = atoi(global.value) <= 0 ? 1 : 0;
	number = abs(atoi(global.value));
	while (number > 0)
	{
		number /= 10;
		size++;
	}
	if (size != strlen(global.value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (!strcmp(global.type, "stack"))
		_stac(stack);
	else
		_queu(stack);
}

/**
 * _stack - stack Emp
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	global.type = "stack";
}

/**
 * _queue - queue Emp
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	global.type = "queue";
}

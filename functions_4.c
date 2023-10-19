#include "monty.h"
#include <string.h>

/**
 * _pall - print every node in stack
 *
 * @stack: doubly linked list
 * @line_number: line's num in morty script
 */

void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - print a Top node.
 * @stack: doubly linked list
 * @line_number: line's num in morty script
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - pop The top of Node.
 * @stack: doubly linked list
 * @line_number: line's num in morty script
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *poped;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	poped = *stack;
	(*stack) = (*stack)->next;
	global.head = (*stack);
	if (*stack)
		(*stack)->prev = NULL;
	free(poped);
	poped = NULL;
}

/**
 * _mul - multy 2 elements
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *target;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	target = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	global.head = *stack;
	free(target);
}

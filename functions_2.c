#include "monty.h"


/**
 * _swap - swaps 2 elements
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = (*stack)->n - (*stack)->next->n;
	(*stack)->n = (*stack)->n - (*stack)->next->n;
}

/**
 * _add - adds 2 elements
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *target;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	target = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	global.head = *stack;
	free(target);
}

/**
 * _nop - nothing to do
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * _sub - sub 2 elements
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *target;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	target = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	global.head = *stack;
	free(target);
}

/**
 * _div - div 2 elements
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *target;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	else if (!(*stack)->n)
	{
		fprintf(stderr, "L%u: division by zero\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);

	}
	target = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	global.head = *stack;
	free(target);
}


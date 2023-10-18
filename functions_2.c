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
		printf("L%u: can't swap, stack too short\n", line_number);
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
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	target = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;

	free(target);
}


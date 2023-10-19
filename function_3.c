#include "monty.h"
#include <stdio.h>
/**
 * _mod - mod 2 elements
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *target;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
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
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	global.head = *stack;
	free(target);
}

/**
 * _pchar - print char at top  elements
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		free_stack();
		exit(EXIT_FAILURE);

	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - print string at top  elements
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	else
	{
		while ((*stack)->n > 0 && (*stack)->n <= 127 && *stack)
		{
			printf("%c", (*stack)->n);
			*stack = (*stack)->next;
		}
		printf("\n");
	}
}

/**
 * _rotl - rotates stack at top.
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *end = NULL;

	(void) line_number;
	if (stack && *stack && (*stack)->next)
	{
		tmp = *stack;
		(*stack) = (*stack)->next;
		global.head = (*stack);
		tmp->next = NULL;
		(*stack)->prev = NULL;
		end = *stack;
		while (end->next)
			end = end->next;
		end->next = tmp;
		tmp->prev = end;
	}
}

/**
 * _rotr - rotates stack.
 *
 * @stack: doubly linked list
 * @line_number: monty script current line
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void) line_number;
	if (stack && *stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->next = (*stack);
		tmp->prev = NULL;
		(*stack)->prev = tmp;
		global.head = tmp;
	}
}

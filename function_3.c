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
		fclose(global.fd);
		free(global.line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	else if (!(*stack)->n)
	{
		fprintf(stderr, "L%u: division by zero\n",
				line_number);
		fclose(global.fd);
		free(global.line);
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
		fclose(global.fd);
		free(global.line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		fclose(global.fd);
		free(global.line);
		free_stack();
		exit(EXIT_FAILURE);

	}
	printf("%c\n", (*stack)->n + '0');
}

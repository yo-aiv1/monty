#include "monty.h"

/**
 * function_hundler - opcode hundler.
 * @stack: node's head.
 * @line_number: line's num in morty script.
 */

void function_hundler(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	instruction_t functions[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add}, {NULL, NULL}
	};

	while (functions[i].opcode != NULL)
	{
		if (strcmp(global.op_name, functions[i].opcode) == 0)
		{
			functions[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (functions[i].opcode == NULL)
	{
		printf("L%u: unknown instruction %s\n", line_number, global.op_name);
		exit(EXIT_FAILURE);
	}
}

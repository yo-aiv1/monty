#include "monty.h"


/**
 * free_stack - free memory.
 */

void free_stack(void)
{
	if (global.head != NULL)
	{
		while (global.head->next != NULL)
		{
			global.head = global.head->next;
			free(global.head->prev);
		}
		free(global.head);
	}
}

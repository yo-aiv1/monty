#include "main.h"

global_t global;


/**
 * main - monty interprets.
 * @argc: number of arguments.
 * @argv: number of arguments.
 * Return: EXIT_SUCCESS if it successed or EXIT_FAILURE if it failed.
 */

int main(int argc, char **argv)
{
	stack_t *head = NULL;
	FILE *fp;
	char *line = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;

	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	atexit(free_stack);

	while (getline(&line, &line_length, fp) != -1)
	{
		global.op_name = strtok(line, "\n\t\r\v\f ");
		global.value = strtok(NULL, "\n\t\r\v\f ");

		if (global.op_name != NULL)
		{
			function_hundler(&head, line_number);
		}
		line_number++;
	}

	free(line);
	fclose(fp);

	exit(EXIT_SUCCESS);
}

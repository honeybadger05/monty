#include "monty.h"
#define BUFSIZE 64

char *operand;

/**
 * main - Monty interpreter
 * @argc: Number of arguments
 * @argv: List of arguments
 * Return: Nothing
 */
int main(int argc, char const *argv[])
{
	line_t *lines;
	char **line_tokens;
	int line_number;
	stack_t *stack;
	char *content;
	void (*func)(stack_t **, unsigned int);

	stack = NULL;

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	lines = textfile_to_array(argv[1]);
	if (lines == NULL)
		return (0);

	line_number = 0;
	while ((lines + line_number)->content != NULL)
	{
		content = (lines + line_number)->content;
		line_tokens = split_line(content);
		operand = line_tokens[1];

		func = get_op_func(line_tokens[0]);
		if (func == NULL)
		{
			/* TODO: Refactor: Edit more efficient way to free memory on exit */
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number + 1, line_tokens[0]);
			free(line_tokens);
			free_stack(stack);
			free_lines(lines);
			exit(EXIT_FAILURE);
		}

		func(&stack, line_number + 1);
		free(line_tokens);
		line_number++;
	}

	free_stack(stack);
	free_lines(lines);
	return (0);
}

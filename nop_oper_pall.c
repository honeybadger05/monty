#include "monty.h"

/**
 * perform_nop - Performs no operation
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation appears
 *
 * Description: This function does nothing and serves as a placeholder for no operation.
 * Return: Void
 */
void perform_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

#include "monty.h"

/**
 * get_operator_function - Get the corresponding function for an operator
 * @opcode: Pointer to the operator
 * @line: Line number where the operator appears
 * @stack: Pointer to the top of the stack
 *
 * Description: This function retrieves the corresponding function for the given operator.
 * Return: Void function pointer to the corresponding operator function.
 */
void (*get_operator_function(char *opcode, unsigned int line, stack_t **stack))(stack_t **, unsigned int)
{
	int i;

	instruction_t operation[] = {
		{"pall", get_pall},
		{"add", get_add},
		{"pint", get_pint},
		{"swap", get_swap},
		{"pop", get_pop},
		{"sub", get_sub},
		{"div", get_div},
		{"mul", get_mul},
		{"mod", get_mod},
		{"nop", get_nop},
		{"rotl", get_rotl},
		{"rotr", get_rotr},
		{"pchar", get_pchar},
		{"pstr", get_pstr},
		{NULL, NULL}
	};

	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(operation[i].opcode, opcode) == 0)
		{
			return (operation[i].f);
		}
	}

	fprintf(stderr, "L%u: Unknown instruction %s\n", line, opcode);
	fclose(file);
	get_free(*stack);
	exit(EXIT_FAILURE);
}

#include "monty.h"

/**
 * print_stack - Print all elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function prints all elements of the stack.
 * Return: Void
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

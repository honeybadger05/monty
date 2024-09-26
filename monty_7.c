#include "monty.h"

/**
 * op_push - Adds elements to a stack
 * @stack: Pointer to the first node/element in a stack
 * @line_number: The line within the stack
 * Return: Nothing
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (operand == NULL || _atoi(operand, &value) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	new_node->n = value;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * op_pall - Prints the data of all nodes in a stack
 * @stack: Pointer to the head node pointer
 * @line_number: The line number
 * Return: Void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_pint - Prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the head node pointer
 * @line_number: The line number
 * Return: Void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	printf("%d\n", temp->n);
}

#include "monty.h"

/**
 * print_char - Print the character at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function prints the character at the top of the stack.
 * Return: Void
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}

	if (!isascii((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

#include "monty.h"

/**
 * print_top - Print the top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function prints the top element of the stack.
 * Return: Void
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

#include "monty.h"

/**
 * pop_top - Pop the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function pops the top element of the stack.
 * Return: Void
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	*stack = (*stack)->next;

	if (first->next)
	{
		first->next->prev = NULL;
	}

	free(first);
}

#include "monty.h"

/**
 * rotate_right - Rotates the top to the tail of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function rotates the top element of the stack to the tail.
 * Return: Void
 */
void rotate_right(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		;
	}
	else
	{
		first = last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
	}
}

#include "monty.h"

/**
 * subtract - Subtracts the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function subtracts the top element from the second element
 *              on the stack and stores the result in the second element.
 * Return: Void
 */
void subtract(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't subtract, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		first = *stack;
		second = first->next;
		second->n -= first->n;
		*stack = second;
		(*stack)->prev = NULL;
		free(first);
	}
}

#include "monty.h"

/**
 * swap_elements - Swaps the top two elements on the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function swaps the positions of the top two elements on
 *              the stack.
 * Return: Void
 */
void swap_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		first = *stack;
		second = first->next;
		*stack = second;
		first->next = second->next;
		if (second->next != NULL)
		{
			second->next->prev = first;
		}
		second->prev = NULL;
		second->next = first;
		first->prev = second;
	}
}

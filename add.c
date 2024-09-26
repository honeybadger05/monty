#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation appears
 *
 * Description: This function adds the top two elements of the stack.
 * Return: Nothing on success. On failure, exits with EXIT_FAILURE.
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *first_element, *second_element;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: Unable to add, stack has insufficient elements\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		first_element = *stack;
		second_element = first_element->next;
		second_element->n += first_element->n;
		*stack = second_element;
		(*stack)->prev = NULL;
		free(first_element);
	}
}

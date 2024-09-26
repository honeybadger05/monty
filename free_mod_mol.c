#include "monty.h"

/**
 * free_stack - Frees the stack
 *
 * @stack: Stack pointer
 *
 * Description: This function recursively frees the stack.
 * Return: Void
 */
void free_stack(stack_t *stack)
{
	if (stack)
	{
		free_stack(stack->next);
		free(stack);
	}
}

#include "monty.h"

/**
 * calculate_modulus - Calculates the modulus of the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation appears
 *
 * Description: This function calculates the modulus of the top two elements of the stack.
 * Return: Nothing on success. On failure, exits with EXIT_FAILURE.
 */
void calculate_modulus(stack_t **stack, unsigned int line_number)
{
	stack_t *first_element, *second_element;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: Unable to perform modulus, stack has insufficient elements\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: Division by zero\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		first_element = *stack;
		second_element = first_element->next;
		second_element->n %= first_element->n;
		*stack = second_element;
		(*stack)->prev = NULL;
		free(first_element);
	}
}

#include "monty.h"

/**
 * multiply_top_two_elements - Multiplies the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the operation appears
 *
 * Description: This function multiplies the top two elements of the stack.
 * Return: Nothing on success. On failure, exits with EXIT_FAILURE.
 */
void multiply_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *first_element, *second_element;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: Unable to multiply, stack has insufficient elements\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		first_element = *stack;
		second_element = first_element->next;
		second_element->n *= first_element->n;
		*stack = second_element;
		(*stack)->prev = NULL;
		free(first_element);
	}
}

#include "monty.h"

/**
 * print_string - Print the ASCII values of elements
 * @stack: Pointer to the head of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function prints the ASCII values of elements.
 * Return: Void
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;

	(void)line_number;

	if ((stack == NULL) || (*stack == NULL))
	{
		printf("\n");
	}
	else
	{
		while (top_node != NULL)
		{
			if ((top_node->n > 0) && (isascii(top_node->n)))
			{
				printf("%c", top_node->n);
				top_node = top_node->next;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
}

#include "monty.h"

/**
 * push_element - Pushes an element onto the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the instruction appears
 * @temp: Pointer to the instruction
 *
 * Description: This function pushes an element onto the top of the stack.
 * Return: Void
 */
void push_element(stack_t **stack, unsigned int line_number, char *temp)
{
	stack_t *new_top;

	(void)line_number;

	if (temp == NULL || is_digit(temp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
		if (is_digit(temp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			get_free(*stack);
			exit(EXIT_FAILURE);
		}
	}

	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	new_top->n = atoi(temp);
	new_top->next = NULL;
	new_top->prev = NULL;

	if (*stack)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
	}

	*stack = new_top;
}

/**
 * is_digit - Checks if a string is a digit
 * @str: Pointer to the string
 *
 * Return: 1 if the string is a digit, 0 otherwise
 */
int is_digit(char *str)
{
	int i = 0;

	if (str[i] == '-')
	{
		i++;
	}

	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return 1;
		}
		i++;
	}

	return 0;
}

#include "monty.h"

/**
 * rotate_left - Rotates the tail to the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the instruction appears
 *
 * Description: This function rotates the tail of the stack to the top.
 * Return: Void
 */
void rotate_left(stack_t **stack, unsigned int line_number)
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
		*stack = first->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}

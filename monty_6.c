#include "monty.h"

/**
 * get_op_func - Select the correct operation function asked by user
 * @s: Operator argument
 *
 * Return: Function pointer corresponding to operator given
 */
void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint}, /* Add new functions here */
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL && strcmp(ops[i].opcode, s))
		i++;
	return ops[i].f;
}

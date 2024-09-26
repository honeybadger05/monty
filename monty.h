#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structs */
typedef struct stack_s {
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct line_s {
	char *content;
	int number;
} line_t;

typedef struct monty_s {
	int error;
	int line;
	char *token;
} monty_t;

typedef struct instruction_s {
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global variables */
extern FILE *file;
extern char *operand;

/* Function prototypes */
line_t *textfile_to_array(const char *filename);
char **split_line(char *line);
void free_stack(stack_t *head);
void free_lines(line_t *lines);
void monty_error(monty_t *monty);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
int _atoi(char *s, int *n);
void get_swap(stack_t **stack, unsigned int line_number);
void get_sub(stack_t **stack, unsigned int line_number);
void get_rotr(stack_t **stack, unsigned int line_number);
void get_free(stack_t *stack);
void get_nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

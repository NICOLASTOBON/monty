#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Handle commands*/
void handle_command(char *argv);

/*get_ opcode commands*/
int get_opc(stack_t **stack, char *arg, char *item, int count);

/*Options funcs1.c*/
void _push(stack_t **stack, int num);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_num);
void stack_node(stack_t **stack, stack_t *item);

/* Free Double linked list */
void free_dlistint(stack_t *stack);

/*Helpers*/
int _isdigit(char *c);

/* handle errors */
void handle_error(unsigned int line_number, char *op, int err);
void push_error(FILE *fd, char *line, stack_t *stack, int count);
void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item);

#endif /*HOLBERTON*/
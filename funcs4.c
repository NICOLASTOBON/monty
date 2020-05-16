#include "monty.h"
/**
 * _rotl - rotate number
 * @stack: Stack.
 * @line_number: Number of line
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL, *new = NULL;
	int num;

	(void)line_number;
	if (*stack != NULL)
	{
		current = *stack;
		new = current->next;
		num = current->n;

		while (new != NULL)
		{
			current->n = new->n;
			current = new;
			new = new->next;
		}
		current->n = num;
	}
}
/**
 * _rotr - rotate number
 * @stack: Stack.
 * @line_number: Number of line
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL, *new = NULL;
	int num;

	(void)line_number;
	if (*stack != NULL)
	{
		current = *stack;
		new = current->next;
		while (new->next != NULL)
		{
			current = new;
			new = new->next;
		}
		num = new->n;
		while (current != NULL)
		{
			new->n = current->n;
			new = current;
			current = current->prev;
		}
		new->n = num;
	}
}

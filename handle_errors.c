#include "monty.h"
/**
 * exit_program - free all
 * Return: void
 */
void exit_program(void)
{
	if (command.fd  != NULL)
		fclose(command.fd);
	if (command.line  != NULL)
		free(command.line);
	if (command.stack != NULL)
		free_dlistint(command.stack);
}
/**
 * push_error - handle push error
 * @count: is a line command
 */
void push_error(int count)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
	exit_program();
	exit(EXIT_FAILURE);
}

/**
 * ins_error - Error handler
 * @count: is a line command
 * @item: number
 */
void ins_error(char *count, int item)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", item, count);
	exit_program();
	exit(EXIT_FAILURE);
}

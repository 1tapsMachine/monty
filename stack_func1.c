#include "monty.h"


/**
 * append_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void append_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp_var;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp_var = head;
	head = *new_node;
	head->next = temp_var;
	temp_var->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_var;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp_var = *stack;
	while (temp_var != NULL)
	{
		printf("%d\n", temp_var->n);
		temp_var = temp_var->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_var;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	temp_var = *stack;
	*stack = temp_var->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp_var);
}

/**
 * get_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void get_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

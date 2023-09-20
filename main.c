#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	delete_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @data: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int data)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = data;
	return (node);
}

/**
 * delete_nodes - Frees nodes in the stack.
 */
void delete_nodes(void)
{
	stack_t *temp;

	if (stack_head == NULL)
		return;

	while (stack_head != NULL)
	{
		temp = stack_head;
		stack_head = stack_head->next;
		free(temp);
	}
}

/**
 * enqueue_node - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @line_num: line number of the opcode.
 */
void enqueue_node(stack_t **new_node,
__attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (stack_head == NULL)
	{
		stack_head = *new_node;
		return;
	}
	temp = stack_head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}

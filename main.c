#include "monty.h"
stack_t *head = NULL;

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
	delete_node();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * delete_node - Frees nodes in the stack.
 */
void delete_node(void)
{
	stack_t *temp_var;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp_var = head;
		head = head->next;
		free(temp_var);
	}
}


/**
 * append_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void append_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (temp_var->next != NULL)
		temp_var = temp_var->next;

	temp_var->next = *new_node;
	(*new_node)->prev = temp_var;

}

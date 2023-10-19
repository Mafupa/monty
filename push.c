#include "monty.h"

void add_node(stack_t **head, int n)
{
	stack_t *new, *cur;

	if (!head)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
		return;
	new->n = n;
	new->next = NULL;
	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->prev = cur;

}

void add_node_end(stack_t **head, int n)
{
	stack_t *new, *cur;

	if (!head)
		exit(EXIT_FAILURE);
	new = malloc(sizeof(stack_t));
	if (!new)
		exit(EXIT_FAILURE);
	new->n = n;
	new->next = NULL;
	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->prev = cur;
}

void _push(stack_t **stack, unsigned int line_number)
{
	int i = 0, n;

	if (bus.args[0] == '-')
		i++;
	for (; bus.args[i]; i++)
	{
		if (bus.args[i] < 'a' || bus.args[i] > 'z')
		{
			fprintf(stderr, "Not a number");
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(bus.args);
	add_node(stack, n);
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;

	if (!cur)
		return;
	while(cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}

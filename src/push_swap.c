#include "../includes/push_swap.h"

void free_stack(t_node *head)
{
	t_node *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
int main(int argc, char **argv)
{
	t_stack stack;
	// t_node *current;

	stack.a = NULL;
	stack.b = NULL;

	if (argc < 2)
		return (1);
	if (!check_arguments(argc, argv, &stack))
	{
		write(2, "Error", 6);
	}
	else
	{
		sort_numbers(&a, &b);
		// sa(&stack);
		// current = stack.a;
		// while (current)
		// {
		// 	printf("%d\n", current->value);
		// 	current = current->next;
		// }
	}
		//sort_numbers(&a, &b);
	free_stack(stack.a);
	//free_stack(&b);
	return (0);
}

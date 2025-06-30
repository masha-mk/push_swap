#include "../includes/push_swap.h"

int sorted(t_stack *stack)
{
	t_node *first;
	first = stack->a;
	while (first && first->next != NULL)
	{
		if (first->index > first->next->index)
			return(0);
		first = first->next;
	}
	return (1);
}

void sort_stack(t_stack *stack)
{
	int size;

	size = stack_size(stack->a);
	if (size == 2)
		sa(stack);
	else if (size == 3)
		sort_three(stack);
	else if (size <= 5)
	 	sort_five(stack);
	// else
	// 	sort_numbers(stack);
}
int stack_size(t_node *head)
{
	int size;
	t_node *current;

	current = head;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
int main(int argc, char **argv)
{
	t_stack stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc < 2)
		return (0);
	if (!check_arguments(argc, argv, &stack))
	{
		write(2, "Error", 5);
		return (1);
	}
	assign_indexes(stack.a);
	if (sorted(&stack))
		return (0);
	else
		sort_stack(&stack);
	free_stack(stack.a);
	free_stack(stack.b);
	return (0);
}
// int main(int argc, char **argv)
// {
// 	t_stack stack;
// 	// t_node *current;

// 	stack.a = NULL;
// 	stack.b = NULL;

// 	if (argc < 2)
// 		return (1);
// 	if (!check_arguments(argc, argv, &stack))
// 	{
// 		write(2, "Error", 6);
// 	}
// 	else
// 	{
// 		if (argv == 3)
// 			sa(stack);
// 		else if (argv == 4)
			
// 		//sort_numbers(&a, &b);
		
// 		// sa(&stack);
// 		// current = stack.a;
// 		// while (current)
// 		// {
// 		// 	printf("%d\n", current->value);
// 		// 	current = current->next;
// 		// }
// 	}
// 		//sort_numbers(&a, &b);
// 	free_stack(stack.a);
// 	//free_stack(&b);
// 	return (0);
// }
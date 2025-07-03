/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:55:40 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 20:12:16 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void print_stack(t_node *first, char name)
// {
//     printf("Pile %c : ", name);
//     while (first)
//     {
//         printf("%d ", first->value);
//         first = first->next;
//     }
//     printf("\n");
// }
int	check_arguments(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_and_add(argv[i], a))
			return (0);
		i++;
	}
	return (1);
}

int	sorted(t_stack *stack)
{
	t_node	*first;

	first = stack->a;
	while (first && first->next != NULL)
	{
		if (first->index > first->next->index)
			return (0);
		first = first->next;
	}
	return (1);
}

void	sort_stack(t_stack *stack)
{
	int	size;

	size = stack_size(stack->a);
	if (size == 2)
		sa(stack);
	else if (size == 3)
		tiny_sort(stack);
	else if (size <= 5)
		small_sort(stack);
	else
		big_sort(stack);
}

int	stack_size(t_node *head)
{
	int		size;
	t_node	*current;

	current = head;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc < 2)
		return (0);
	if (!check_arguments(argc, argv, &stack))
	{
		write(2, "Error\n", 6);
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

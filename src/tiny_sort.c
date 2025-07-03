/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:00:17 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 19:10:06 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_index(t_stack *stack)
{
	t_node	*temp;
	int		min_index;
	int		pos;
	int		i;

	pos = 0;
	i = 0;
	temp = stack->a;
	if (!temp)
		return (0);
	min_index = temp->index;
	while (temp)
	{
		if (temp->index < min_index)
		{
			min_index = temp->index;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

void	push_smallest_to_b(t_stack *stack)
{
	int	pos;

	pos = find_smallest_index(stack);
	push_to_b(stack, pos);
}

void	tiny_sort(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->index;
	b = stack->a->next->index;
	c = stack->a->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	small_sort(t_stack *stack)
{
	int	size;
	int	times;

	size = stack_size(stack->a);
	times = size - 3;
	while (times--)
		push_smallest_to_b(stack);
	tiny_sort(stack);
	while (stack->b)
		pa(stack);
}

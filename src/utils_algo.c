/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:00:20 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/04 10:06:56 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b(t_stack *stack, int pos)
{
	int	size;

	size = stack_size(stack->a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack);
	}
	pb(stack);
}

int	get_chunk_pos(t_node *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	rotate_to_top_b(t_stack *s, int pos)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(s->b);
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			rb(s);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rrb(s);
			i++;
		}
	}
}

int	find_max_position(t_node *b)
{
	int	max;
	int	max_pos;
	int	i;

	if (!b)
		return (0);
	max = b->index;
	max_pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = i;
		}
		b = b->next;
		i++;
	}
	return (max_pos);
}

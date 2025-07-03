/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:59:36 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 19:03:29 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 20)
		return (size);
	else if (size <= 100)
		return (20);
	else
		return (55);
}

static int	get_chunk_pos_filtered(t_node *a, int min, int max)
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

static void	push_chunk_to_b(t_stack *stack, int min, int max)
{
	int		pos;
	int		i;
	t_node	*tmp;

	while (1)
	{
		pos = get_chunk_pos_filtered(stack->a, min, max);
		if (pos == -1)
			break ;
		tmp = stack->a;
		i = pos;
		while (i-- > 0)
			tmp = tmp->next;
		if (tmp->index >= (min + max) / 2)
			push_to_b(stack, pos);
		else
		{
			push_to_b(stack, pos);
			rb(stack);
		}
	}
}

static void	push_back_to_a(t_stack *stack)
{
	int	max_pos;

	while (stack->b)
	{
		max_pos = find_max_position(stack->b);
		rotate_to_top_b(stack, max_pos);
		pa(stack);
	}
}

void	big_sort(t_stack *stack)
{
	int	size;
	int	chunk_size;
	int	i;

	size = stack_size(stack->a);
	chunk_size = get_chunk_size(size);
	i = 0;
	while (i < size)
	{
		push_chunk_to_b(stack, i, i + chunk_size - 1);
		i = i + chunk_size;
	}
	push_back_to_a(stack);
}

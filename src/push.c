/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:59:55 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 19:02:14 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_node **from, t_node **to)
{
	t_node	*element;

	if (!*from)
		return ;
	element = (*from);
	*from = (*from)->next;
	element->next = *to;
	*to = element;
}

void	pa(t_stack *stack)
{
	push(&stack->b, &stack->a);
	ft_putstr("pa\n");
}

void	pb(t_stack *stack)
{
	push(&stack->a, &stack->b);
	ft_putstr("pb\n");
}

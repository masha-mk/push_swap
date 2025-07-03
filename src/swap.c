/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:00:13 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 19:03:05 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_node **head)
{
	int	tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
	tmp = (*head)->index;
	(*head)->index = (*head)->next->index;
	(*head)->next->index = tmp;
}

void	sb(t_stack *stack)
{
	swap(&stack->b);
	ft_putstr("sb\n");
}

void	sa(t_stack *stack)
{
	swap(&stack->a);
	ft_putstr("sa\n");
}

void	ss(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	ft_putstr("ss\n");
}

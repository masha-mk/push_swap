/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:00:01 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 19:01:55 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	*head = (*head)->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack *stack)
{
	rotate(&stack->a);
	ft_putstr("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(&stack->b);
	ft_putstr("rb\n");
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:59:58 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 19:09:31 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	while (first->next->next != NULL)
		first = first->next;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(t_stack *stack)
{
	rev_rotate(&stack->a);
	ft_putstr("rra\n");
}

void	rrb(t_stack *stack)
{
	rev_rotate(&stack->b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_putstr("rrr\n");
}

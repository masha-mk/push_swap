/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:59:39 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 19:10:30 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return ;
	}
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

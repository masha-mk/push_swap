/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:41:48 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/03 18:25:19 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid_nb(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if ((str[0] == '-' || str[0] == '+'))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	is_duplicate(t_stack *stack, int nb)
{
	t_node	*current;

	current = stack->a;
	while (current)
	{
		if (current->value == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	add_to_stack(t_stack *stack, int nb)
{
	t_node	*new;
	t_node	*current;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = nb;
	new->index = -1;
	new->next = NULL;
	if (stack->a == NULL)
	{
		stack->a = new;
		return (1);
	}
	current = stack->a;
	while (current->next)
		current = current->next;
	current->next = new;
	return (1);
}

int	parse_and_add(char *arg, t_stack *a)
{
	int		j;
	char	**arr;
	int		nb;

	arr = ft_split(arg);
	if (!arr)
		return (0);
	j = 0;
	while (arr[j])
	{
		if (!is_valid_nb(arr[j]))
			return (free_split(arr), 0);
		nb = ft_atoi(arr[j]);
		if ((nb == 0 && arr[j][0] != '0') || is_duplicate(a, nb)
			|| !add_to_stack(a, nb))
			return (free_split(arr), 0);
		j++;
	}
	free_split(arr);
	return (1);
}

void	assign_indexes(t_node *head)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = head;
	while (current)
	{
		index = 0;
		compare = head;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamakaro <mamakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:58:43 by mamakaro          #+#    #+#             */
/*   Updated: 2025/07/04 10:06:37 by mamakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBS
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// STRUCTURES

//Linked List
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;
//Structure of nodes
typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
}					t_stack;

// MOVEMENTS
// swap
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack);
// rotate
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);
// reverse-rotate
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);
// push
void				pa(t_stack *stack);
void				pb(t_stack *stack);

// PARSING
void				assign_indexes(t_node *head);
int					check_arguments(int argc, char **argv, t_stack *a);
int					parse_and_add(char *arg, t_stack *a);
// ALGO
void				tiny_sort(t_stack *stack);
void				small_sort(t_stack *stack);
void				big_sort(t_stack *stack);
// ALGO UTILS
int					get_chunk_pos(t_node *a, int min, int max);
void				rotate_to_top_b(t_stack *s, int pos);
int					find_max_position(t_node *b);
void				push_to_b(t_stack *stack, int pos);
// UTILS
int					stack_size(t_node *head);
char				**ft_split(char *str);
int					ft_atoi(char *str);
void				ft_putstr(char *str);
// Free
void				free_split(char **str);
void				free_stack(t_node *head);

void				print_stack(t_node *first, char name);

#endif
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//LIBS
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// STRUCTURES
typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;


typedef struct s_stack
{
    t_node *a;
    t_node *b;
}  t_stack;

    // MOVEMENTS
//swap
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *stack);
//rotate
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *stack);
//reverse-rotate
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack);
//push
void pa(t_stack *stack);
void pb(t_stack *stack);


    // PARSING
void assign_indexes(t_node *head);
int check_arguments(int argc, char **argv, t_stack *a);
    // ALGO
void tiny_sort(t_stack *stack);
void small_sort(t_stack *stack);
void big_sort(t_stack *stack);
    //ALGO UTILS
int has_chunk_values(t_node *a, int min, int max);
int get_chunk_pos(t_node *a, int min, int max);
int get_b_insert_pos(t_node *b, int index);
void rotate_to_top_b(t_stack *s, int pos);
int find_max_position(t_node *b);

    // UTILS
int check_arguments(int argc, char **argv, t_stack *a);
int stack_size (t_node *head);
char **ft_split(char *str);
int ft_atoi(char *str);
void ft_putstr(char *str);
void push_to_b(t_stack *stack, int pos);
    //Free
void	free_split(char **str);
void free_stack(t_node *head);


#endif
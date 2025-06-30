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





// PARSING
void assign_indexes(t_node *head);


// ALGO
void sort_three(t_stack *stack);
// UTILS
int check_arguments(int argc, char **argv, t_stack *a);
int stack_size (t_node *head);
char **ft_split(char *str);
int ft_atoi(char *str);
static int ft_atoi_check(long long res, int sign);
void ft_putstr(char *str);

//Free
void	free_split(char **str);
void free_stack(t_node *head);




#endif
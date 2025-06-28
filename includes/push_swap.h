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
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *stack);


// PARSING


// ALGO

// UTILS
int check_arguments(int argc, char **argv, t_stack *a);
char **ft_split(char *str);
int ft_atoi(char *str);

//Free
void	free_split(char **str);
void free_stack(t_node *head);




#endif
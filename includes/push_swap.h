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
    struct s_node *next;
} t_node;


typedef struct s_stack
{
    t_node *a;
    t_node *b;
}  t_stack;

// MOVEMENTS


// PARSING


// ALGO


// UTILS


#endif
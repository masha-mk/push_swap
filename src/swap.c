#include "../includes/push_swap.h"
//Functions with accepted movements (sa, sb, rr etc)

void sa(t_stack *stack)
{
    t_node *first;
    t_node *second;
    int temp;

    if (!stack->a || !stack->a->next)
        return;
    first = stack->a;
    second = stack->a->next;

    temp = first->value;
    first->value = second->value;
    second->value = temp;
}
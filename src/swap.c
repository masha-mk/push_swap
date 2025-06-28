#include "../includes/push_swap.h"
//Functions with accepted movements (sa, sb, rr etc)

static void swap(t_node **head)
{
int tmp;

if(!*head || !(*head)->next)
    return;
tmp = (*head)->value;
(*head)->value = (*head)->next->value;
(*head)->next->value = tmp;

tmp = (*head)->index;
(*head)->index = (*head)->next->index;
(*head)->next->index = tmp;
}
void sb(t_stack *stack)
{
    swap(&stack->b);
}
void sa(t_stack *stack)
{
    swap(&stack->a);
}
void ss(t_stack *stack)
{
    sa(stack);
    sb(stack);
}
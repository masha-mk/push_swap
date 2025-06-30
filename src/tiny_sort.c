#include "../includes/push_swap.h"

// static int find_highest_index(t_node *head)
// {
//     int index;
//     index = head->index;
//     while (head != NULL)
//     {
//         if (head->index > index)
//             index = head->index;
//         head = head->next;
//     }
//     return (index);
// }

void push_smallest_to_b(t_stack *stack)
{
    t_node *temp;
}
void sort_three(t_stack *stack)
{
    int a = stack->a->index;
    int b = stack->a->next->index;
    int c = stack->a->next->next->index;

    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
    printf("index a: %d, b: %d, c: %d\n", a, b, c);
}
void sort_five(t_stack *stack)
{
    int size;
    int times;

    size = stack_size(stack->a);
    times = size - 3;

    while (times--)
        push_smallest_to_b(stack);
    sort_three(stack);
    while (stack->b)
        pa(stack);
}
//ecrire une fonction push to b et return to a


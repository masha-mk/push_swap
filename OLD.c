#include "../includes/push_swap.h"

static int get_chunk_size(int size)
{
    if (size <= 100)
        return (20);
    else
        return (30);
}
static int find_highest_index_pos(t_node *b)
{
    int max_index;
    int max_pos;
    int i;
    t_node *current;

    if (!b)
        return (-1);

    max_index = b->index;
    max_pos = 0;
    i = 0;
    current = b;

    while (current)
    {
        if (current->index > max_index)
        {
            max_index = current->index;
            max_pos = i;
        }
        current = current->next;
        i++;
    }
    return (max_pos);
}

static int find_best_pos_to_push(t_node *a, int chunk_max)
{
    int top;
    int bottom;
    int i;
    int size;
    t_node *current;

    top = -1;
    bottom = -1;
    i = 0;
    size = stack_size(a);
    current = a;
    while (current)
    {
        if (top == -1 && current->index <= chunk_max)
            top = i;
        if (current->index <= chunk_max)
            bottom = i;
        current = current->next;
		i++;
    }
	if (top == -1)
		return (-1);
	if (top <= size - bottom)
		return (top);
	return (bottom);
}
static void push_best_to_b(t_stack *stack, int chunk_max)
{
    int pos;

    pos = find_best_pos_to_push(stack->a, chunk_max);
    if (pos != -1)
         push_to_b(stack, pos);
}
void push_all_chunks(t_stack *stack)
{
    int total = stack_size(stack->a);
    int chunk_size = get_chunk_size(total);
    int chunk_max = chunk_size;

    while (stack->a)
    {
        int pos = find_best_pos_to_push(stack->a, chunk_max);

        if (pos != -1)
        {
            push_best_to_b(stack, pos);
        }
        else
        {
            chunk_max += chunk_size;
        }
    }
}
void push_back_to_a(t_stack *stack)
{
    int max_pos;
    int size;
    int steps;
    while (stack->b)
    {
        max_pos = find_highest_index_pos(stack->b);
        size = stack_size(stack->b);

        if (max_pos <= size / 2)
            while (max_pos-- > 0) 
                rb(stack);
        else
        {
            steps = size - max_pos;
            while (steps-- > 0)
                rrb(stack);
        }
        pa(stack);
    }
}



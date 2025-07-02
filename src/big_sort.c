#include "../includes/push_swap.h"

static int get_chunk_size(int size)
{
    if (size <= 100)
        return (20);
    else
        return (50);
}


static void push_chunk_to_b(t_stack *stack, int min, int max)
{
	while (has_chunk_values(stack->a, min, max))
	{
		int pos;
		int i;
		t_node *tmp;

		pos = get_chunk_pos(stack->a, min, max);
		tmp = stack->a;
		i = pos;
		while (i-- > 0)
			tmp = tmp->next;
		if (tmp->index < (min + max) / 2)
			push_to_b(stack, pos);
		else
		{
			push_to_b(stack, pos);
			rb (stack);
		}
	}
}
static void push_back_to_a(t_stack *stack)
{
	int max_pos;

	while (stack->b)
	{
		max_pos = find_max_position(stack->b);
		rotate_to_top_b(stack, max_pos);
		pa(stack);
	}
}
void big_sort(t_stack *stack)
{
	int size;
	int chunk_size;
	int i;  

	size = stack_size(stack->a);
	chunk_size = get_chunk_size(size);
	i = 0;
    while (i < size)
	{
		push_chunk_to_b(stack, i, i + chunk_size - 1);
		i = i + chunk_size;
	}
	push_back_to_a(stack);
}





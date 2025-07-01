#include "../includes/push_swap.h"

static int get_chunk_size(int size)
{
    if (size <= 100)
        return (20);
    else
        return (30);
}
void big_sort(t_stack *stack)
{
	int size;
	int chunk_size;
	int i;  

	size = stack_size(stack->a);
	chunk_size = get_chunk_size(size);
	i = 0;
    while (stack->a)
	    push_cheapest_to_b(stack);
	push_back_to_a(stack);
}





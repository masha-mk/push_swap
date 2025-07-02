#include "../includes/push_swap.h"

int has_chunk_values(t_node *a, int min, int max)
{
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (1);
		a = a->next;
	}
	return (0);
}
int get_chunk_pos(t_node *a, int min, int max)
{
	int pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}
// int get_b_insert_pos(t_node *b, int index)
// {
// 	int pos;

// 	pos = 0;
// 	while (b)
// 	{
// 		if (index > b->index)
// 			break ;
// 		pos++;
// 		b = b->next;
// 	}
// 	return (pos);
// }
void rotate_to_top_b(t_stack *s, int pos)
{
	int size;
	int i;

	i = 0;
	size = stack_size(s->b);
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			rb(s);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rrb(s);
			i++;
		}
	}
}
int find_max_position(t_node *b)
{
	int max;
	int max_pos;
	int i;

	if (!b)
		return (0);
	max = b->index;
	max_pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = i;
		}
		b = b->next;
		i++;
	}
	return (max_pos);
}

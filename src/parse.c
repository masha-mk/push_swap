#include "../includes/push_swap.h"

static int is_valid_nb(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    if ((str[0] == '-' || str[0] == '+'))
            i++;
    if (str[i] == '\0')
        return (0);  
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}

static int is_duplicate(t_stack *stack, int nb)
{
    t_node *current;

    current = stack->a;
    while (current)
    {
        if (current->value == nb)
            return (1);
        current = current->next;
    }
    return (0);
}

static int add_to_stack(t_stack *stack, int nb)
{
    t_node *new;
    t_node *current;
    
    new = malloc(sizeof(t_node));
    if (!new)
        return (0);
    new->value = nb;
    new->index = -1;
    new->next = NULL;
    if (stack->a == NULL)
    {
        stack->a = new;
        return (1);
    }
    current = stack->a;
    while (current->next)
        current = current->next;
    current->next = new;
    return (1);
}
int check_arguments(int argc, char **argv, t_stack *a)
{
    int i;
    int j;
    char **arr;
    int nb;

    i = 1;
    while (i < argc)
    {
        arr = ft_split(argv[i]);
        if (!arr)
            return (0);
        j = 0;
        while (arr[j])
        {
            if (!is_valid_nb(arr[j]))
                return(free_split(arr), 0);
            nb = ft_atoi(arr[j]);
            if (is_duplicate(a, nb) || !add_to_stack(a, nb))
                return(free_split(arr), 0);
            j++;
        }
        free_split(arr);
        i++;
    }
    return (1);
}

// int main(int argc, char **argv)
// { 
//   t_stack stack;

//   stack.a = NULL;
//   stack.b = NULL;

//   if (!check_arguments(argc, argv, &stack))
//   {
//     write(2, "Error\n", 6);
//     return (1);
//   }
//   t_node *current = stack.a;
//   while (current)
//   {
//     printf("%d\n", current->value);
//     current = current->next;
//   }
//    free_stack(stack.a);
//   return (0);
// }
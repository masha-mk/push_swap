#include "../includes/push_swap.h"

static int ft_atoi_check(long long res, int sign)
{
  if (sign == 1 && res > 2147483647)
    return (0);
  if (sign == -1 && res > 2147483648)
    return (0);
  return (1);
}
int ft_atoi(char *str)
{
    int i;
    int sign;
    long long res;

    i = 0;
    sign = 1;
    res = 0;

    while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if (ft_atoi_check(res, sign))
        return ((int)res * sign);
    return (0);
}
void ft_putstr(char *str)
{
  int i;
  i = 0;

  while (str[i])
  {
    write(1, &str[i], 1);
    i++;
  }
}
void push_to_b(t_stack *stack, int pos)
{
  int size;
  size = stack_size(stack->a);

  if (pos <= size / 2)
  {
    while (pos-- > 0)
      ra(stack);
  }
  else 
  {
    pos = size - pos;
    while (pos-- > 0)
      rra(stack);
  }
  pb(stack);
}

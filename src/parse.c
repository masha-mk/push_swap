#include "../includes/push_swap.h"

int is_valid_nb(char *str)
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
int check_and_parse_arguments(int argc, char **argv, t_stack **a)
{
    int i;
    i = 1;
    while (i < argc)
    {
        if (is_valid_nb(argv[i]))
        {
            //split arguments
            //convertir chaque argument avec atoi
            // verif doublons
            //remplir la pile a
        }
        else
            return (0);
        i++;
    }
}

// int main(int argc, char **argv)
// { 
//     // MAIN CHECK NUMBER
//     int i;
//     i = 1;
//     int verif;

//     while (i < argc)
//     {
//         verif = is_number(argv[i]);
//         if (verif)
//             printf("argv[%d] = \"%s\" -> OK\n", i, argv[i]);
//         else
//             printf("argv[%d] = \"%s\" -> NO\n", i, argv[i]);
//         i++;
//     }
// }
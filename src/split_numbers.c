#include "../includes/push_swap.h"

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int is_sep(char c)
{
    return (c == ' ' || c == '\t');
}
int count_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (!is_sep(str[i] && is_sep(str[i + 1])))
            count++;
        i++;
    }
    return (count);
}

char *word_dup(char *str, int start, int end)
{
    int i;
    char *new;

    i = 0;
    new = (char*)malloc(sizeof(char) * (end - start + 1));
    if (!new)
        return (NULL);
    while (start < end)
    {
        new[i] = str[start];
        i++;
        start++;
    }
    new[i] = '\0';
    return (new);
}


char **ft_split(char *str)
{
    char **res;
    int i;
    int j;
    int start;

    i = 0;
    j = 0;
    res = (char**)malloc(sizeof(char*) * count_words(str) + 1);
    if (!res)
        return (NULL);
    while (str[i])
    {
        while (str[i] && is_sep(str[i]))
            i++;
        start = i;
        while (str[i] && !is_sep(str[i]))
            i++;
        if (i > start)
            res[j++] = word_dup(str, start, i);
    }
    res[j] = NULL;
    return (res);
}
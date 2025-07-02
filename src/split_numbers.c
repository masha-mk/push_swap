#include "../includes/push_swap.h"

static int is_sep(char c)
{
    return (c == ' ' || c == '\t');
}
static int	count_words(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
        while (s[i] && is_sep(s[i]))
            i++;
		if (s[i])
			count++;
        while (s[i] && !is_sep(s[i]))
            i++;
	}
	return (count);
}

static char *word_dup(char *str, int start, int end)
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
    res = (char**)malloc(sizeof(char*) * (count_words(str) + 1));
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
#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (NULL);
	i = -1;
	j = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = 0;
	free(s2);
	return (str);
}

static int    intlen(long long n)
{
    int    i;
    int    neg;

    i = 0;
    neg = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        i++;
        n /= 10;
    }
    return (i + neg);
}

static char    *makeit(long long n, char *str)
{
    size_t    neg;
    size_t    i;

    neg = 0;
    i = intlen(n);
    str[i] = 0;
    i -= 1;
    if (n == 0)
        str[0] = 48;
    while (n != 0 && i >= neg)
    {
        str[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    return (str);
}

char    *ft_ftoa(float n)
{
    char        *str;
    long long    res;

    res = n;
    str = malloc(sizeof(char) * intlen(res) + 1);
    if (!str)
        return (NULL);
    str = makeit(res, str);
    return (str);
}

char    *ft_ulltoa(ull n)
{
    char        *str;
    long long    res;

    res = n;
    str = malloc(sizeof(char) * intlen(res) + 1);
    if (!str)
        return (NULL);
    str = makeit(res, str);
    return (str);
}
#include "utils.h"

char	    *ft_strtok(char *str, char *sep);
static int	ft_isdigit(char c);
static char *ft_strstr(char *ptr, char *sep);


double	ft_atof(char *str)
{
	double	res;
	double	decimal;
	int		sign;
	double	divisor;

	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	res = 0.0;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	decimal = 0.0;
	if (*str == '.')
	{
		str++;
		divisor = 10.0;
		while (ft_isdigit(*str))
		{
			decimal += (*str++ - '0') / divisor;
			divisor *= 10;
		}
	}
	return (res + decimal) * sign;
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strtok(char *str, char *sep)
{
	static char	*ptr;
	static char	*next_ptr;
	char		*tmp;

	if (str)
		ptr = str;
	if (!ptr)
		return (NULL);
	next_ptr = ft_strstr(ptr, sep);
	if (next_ptr)
	{
		tmp = ptr;
		*next_ptr = '\0';
		ptr = next_ptr + ft_strlen(sep);
		return (tmp);
	}
	else
	{
		tmp = ptr;
		ptr = NULL;
		return (tmp);
	}
}

static char *ft_strstr(char *ptr, char *sep)
{
    int i;
    int j;

    i = 0;
    if (sep[i] == '\0')
        return (ptr);
    while (ptr[i])
    {
        j = 0;
        while (ptr[i + j] == sep[j])
        {
            if (sep[j + 1] == '\0')
                return (ptr + i);
            j++;
        }
        i++;
    }
    return (NULL);
}

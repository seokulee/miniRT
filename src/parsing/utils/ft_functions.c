#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!(*s1) && !(*s2))
		return (0);
	while (n-- && (*s1 || *s2))
	{
		if (*s1 > *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 < *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_open(int *fd, char *file)
{
    if ((*fd = open(file, O_RDONLY)) == -1)
        return (-1);
    return (0);
}

int ft_close(int fd)
{
    if (close(fd) == -1)
        return (-1);
    return (0);
}

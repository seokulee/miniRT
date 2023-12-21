#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* gnl */
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

/* split */
char	**ft_split(char const *s, char c);
char	**ft_free_tab(char **tab);

/* functions */
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_strcmp(const char *s1, const char *s2);
int ft_open(int *fd, char *file);
int ft_close(int fd);

/* function2 */
double	ft_atof(char *str);
char	*ft_strtok(char *str, char *sep);

#endif

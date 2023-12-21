#include "parsing.h"

static int	control_identifier(t_world *wolrd, char *id);
static int  count_components(t_world *world, char *open_file);
static int	check_components(t_world *world);
static int	get_components(t_world *world, char *open_file);

int read_rt_file(t_world *world, char *open_file)
{
    if (open_file == NULL || world == NULL)
        return (-1);
    if (ft_strncmp(open_file + ft_strlen(open_file) - 3, ".rt", 3) != 0)
		return (-1);
	if (count_components(world, open_file) == -1)
		return (-1);
	if (check_components(world) == -1)
		return (-1);
	if (get_components(world, open_file) == -1)
		return (-1);
	return (1);
}

static int	control_identifier(t_world *wolrd, char *id)
{
	if (id == NULL)
		return (-1);
	else if (id[0] == '#' || id[0] == '\n')
		return (1);
	else if (!ft_strcmp(id, "A"))
		wolrd->cnt_ambient++;
	else if (!ft_strcmp(id, "C"))
		wolrd->cnt_camera++;
	else if (!ft_strcmp(id, "L"))
		wolrd->cnt_lights++;
	else if (!ft_strcmp(id, "sp") || !ft_strcmp(id, "pl") || \
			!ft_strcmp(id, "cy"))
		wolrd->cnt_objects++;
	else
		return (-1);
	return (1);
}

static int  count_components(t_world *world, char *open_file)
{
    int fd;
    char    *line;
    char    **tab;

    if (ft_open(&fd, open_file) == -1)
        return (-1);
    line = get_next_line(fd);
    while (line)
	{
		tab = ft_split(line, ' ');
		if (control_identifier(world, tab[0]) == -1)
		{
			ft_free_tab(tab);
			free(line);
			return (-1);
		}
		ft_free_tab(tab);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_close(fd));
}

/* check if the informations are appropriate values */
static int	check_components(t_world *world)
{
	if (world->cnt_ambient != 1)
		return (-1);
	if (world->cnt_camera != 1)
		return (-1);
	if (world->cnt_lights < 1)
		return (-1);
	if (world->cnt_objects < 1)
		return (-1);
	return (1);
}

static int	get_components(t_world *world, char *open_file)
{
	int		fd;
	char	*line;
	char	**tab;

	if (ft_open(&fd, open_file) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		if (get_by_id(world, tab) == -1)
		{
			ft_free_tab(tab);
			free(line);
			return (-1);
		}
		ft_free_tab(tab);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_close(fd));
}

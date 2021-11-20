#include "../ft.h"

int		ft_readline(char *buf, int fd)
{
	int		i;

	i = 0;
	while (read(fd, buf + i, 1) && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	return (i);
}

int		ft_fillrow(char **grid, char *buf, int fd, int i)
{
	int		len;
	int		j;

	if (!(grid[i] = (char *)malloc(sizeof(char) * g_width)))
		return (0);
	len = (i > 0) ? ft_readline(buf, fd) : g_width;
	if (len != g_width)
		return (0);
	j = 0;
	while (j < g_width)
	{
		if (ft_is_char(buf[j]))
			grid[i][j] = buf[j];
		else
			return (0);
		j++;
	}
	return (1);
}

char	**ft_getgrid(char *buf, int fd)
{
	int		i;
	char	**grid;
	int		count_valid;

	if (!(grid = (char **)malloc(sizeof(char *) * g_height)))
		return (NULL);
	g_width = ft_readline(buf, fd);
	if (g_width == 0)
	{
		ft_puterr("map error\n");
		return (NULL);
	}
	i = 0;
	count_valid = 0;
	while (i < g_height)
		count_valid += ft_fillrow(grid, buf, fd, i++);
	if (count_valid != g_height || ft_readline(buf, fd) > 0)
	{
		ft_freegrid(grid);
		ft_puterr("map error\n");
		return (NULL);
	}
	return (grid);
}

char	**ft_parse(char *path)
{
	int			fd;
	char		buf[BUF_SIZE + 1];
	char		**grid;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr("map error\n");
		return (NULL);
	}
	ft_readline(buf, fd);
	g_height = ft_atoi(buf);
	ft_set_string(buf);
	if (!g_chars || !ft_check_string())
	{
		ft_puterr("map error\n");
		return (NULL);
	}
	grid = ft_getgrid(buf, fd);
	close(fd);
	return (grid);
}

char	**ft_parse_stdin(void)
{
	char		buf[BUF_SIZE + 1];
	char		**grid;

	ft_readline(buf, 0);
	g_height = ft_atoi(buf);
	ft_set_string(buf);
	if (!g_chars)
	{
		ft_puterr("map error\n");
		return (NULL);
	}
	grid = ft_getgrid(buf, 0);
	return (grid);
}

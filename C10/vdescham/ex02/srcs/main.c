/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:47:12 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 22:56:33 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	invalid_file(char **av, int n)
{
	ft_putstr(basename(av[0]));
	write(1, ": ", 2);
	ft_putstr(av[n]);
	write(1, ": ", 2);
	ft_putstr(strerror(errno));
	write(1, "\n", 1);
}

void	read_file(char **av, int n, int ac, int *valid)
{
	int		fd;
	int		res;
	int		offset;
	char	buf[BUF_SIZE + 1];

	offset = ft_atoi(av[2]);
	fd = open(av[n], O_RDONLY);
	if (fd == -1)
		return (invalid_file(av, n));
	res = read(fd, buf, BUF_SIZE);
	buf[res] = '\0';
	if (offset > res)
		offset = res;
	if (ac > 4)
	{
		if (*valid)
			ft_putstr("\n");
		*valid = 1;
		ft_putstr("==> ");
		ft_putstr(av[n]);
		ft_putstr(" <==\n");
	}
	close(fd);
	ft_putstr(buf + res - offset);
}

void	terminal_writing(int offset)
{
	char	buf[BUF_SIZE + 1];
	int		res;
	int		len;

	res = 0;
	len = 0;
	while ((res = read(0, buf + len, 256)))
	{
		len += res;
	}
	buf[len] = '\0';
	if (offset > len)
		offset = len;
	ft_putstr(buf + len - offset);
}

int		main(int ac, char **av)
{
	int n;
	int valid;

	n = 3;
	valid = 0;
	while (ac > 3 && n < ac && ft_strcmp(av[1], "-c") == 0)
	{
		read_file(av, n, ac, &valid);
		n++;
	}
	if (ac == 3)
	{
		terminal_writing(ft_atoi(av[2]));
	}
}

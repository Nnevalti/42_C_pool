/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:06:43 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 23:04:21 by vdescham         ###   ########.fr       */
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

void	read_file(char *file, char *filename)
{
	int		fd;
	int		res;
	char	buf[BUF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(basename(filename));
		write(1, ": ", 2);
		ft_putstr(file);
		write(1, ": ", 2);
		ft_putstr(strerror(errno));
		write(1, "\n", 1);
		return ;
	}
	res = read(fd, buf, BUF_SIZE);
	buf[res] = '\0';
	close(fd);
	ft_putstr(buf);
}

void	terminal_writing(void)
{
	char	buf[BUF_SIZE + 1];
	int		res;

	while ((res = read(0, buf, BUF_SIZE)))
	{
		buf[res] = '\0';
		ft_putstr(buf);
	}
}

int		main(int ac, char **av)
{
	int n;

	n = 1;
	while (n < ac)
	{
		read_file(av[n], av[0]);
		n++;
	}
	if (ac == 1)
	{
		terminal_writing();
	}
}

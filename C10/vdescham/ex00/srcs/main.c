/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:33:13 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 23:06:20 by vdescham         ###   ########.fr       */
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

void	read_file(char *file)
{
	int		fd;
	int		res;
	char	buf[BUF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	res = read(fd, buf, BUF_SIZE);
	buf[res] = '\0';
	close(fd);
	ft_putstr(buf);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	else if (ac == 3)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	read_file(av[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:32:52 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/14 18:52:06 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		verify_string_validity(char *data)
{
	int i;
	int total;

	total = 0;
	i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= '0' && data[i] <= '4')
		{
			total++;
		}
		else if (data[i] != ' ')
			return (0);
		i++;
	}
	if (total == 16)
		return (1);
	return (0);
}

int		ft_createpov(char *data, int (*pov)[4])
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	if (!verify_string_validity(data))
		return (0);
	while (data[i] != '\0')
	{
		if (data[i] >= '0' && data[i] <= '4' && count < 4 && j < 4)
		{
			pov[j][count] = data[i] - '0';
			count++;
		}
		if (count == 4)
		{
			count = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_creategrid(int (*grid)[4])
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			grid[y][x] = 0;
			x++;
		}
		y++;
		x = 0;
	}
}

int		main(int argc, char **argv)
{
	int pov[4][4];
	int grid[4][4];

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!ft_createpov(argv[1], pov))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_creategrid(grid);
	if (!ft_backtracking(pov, grid, 0, 0))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_printgrid(grid);
}

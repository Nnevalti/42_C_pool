/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:29:53 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/14 18:40:00 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		placenb(int nb, int (*grid)[4], int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		if (grid[y][i] == nb)
			return (0);
		i++;
	}
	j = 0;
	while (j < 4)
	{
		if (grid[j][x] == nb)
			return (0);
		j++;
	}
	return (1);
}

int		ft_backtracking(int (*pov)[4], int (*grid)[4], int y, int x)
{
	int nb;

	nb = 0;
	if (y == 4 && checkcol(pov, grid, 0, 3))
		return (1);
	if (x == 4 && checkrow(pov, grid, y, 0))
		if (ft_backtracking(pov, grid, y + 1, 0) == 1)
			return (1);
	while (nb < 4)
	{
		nb++;
		if (placenb(nb, grid, x, y) && x < 4 && y < 4)
		{
			grid[y][x] = nb;
			if (y == 3 && !checkcol(pov, grid, 0, x))
			{
				grid[y][x] = 0;
				return (0);
			}
			if (ft_backtracking(pov, grid, y, x + 1) == 1)
				return (1);
			grid[y][x] = 0;
		}
	}
	return (0);
}

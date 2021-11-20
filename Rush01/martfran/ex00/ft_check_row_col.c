/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_row_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:37:18 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/14 18:37:20 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	checkpovcount(int pov, int *max, int *povcount)
{
	if (pov > *max)
	{
		*max = pov;
		(*povcount)++;
	}
}

int		checkrow(int (*pov)[4], int (*grid)[4], int y, int x)
{
	int max;
	int povcount;

	max = 0;
	povcount = 0;
	while (x < 4)
	{
		checkpovcount(grid[y][x], &max, &povcount);
		x++;
	}
	if (povcount != pov[2][y])
		return (0);
	max = 0;
	povcount = 0;
	while (x-- > 0)
	{
		checkpovcount(grid[y][x], &max, &povcount);
	}
	if (povcount != pov[3][y])
		return (0);
	return (1);
}

int		checkcol(int (*pov)[4], int (*grid)[4], int y, int x)
{
	int max;
	int povcount;

	max = 0;
	povcount = 0;
	while (y < 4)
	{
		checkpovcount(grid[y][x], &max, &povcount);
		y++;
	}
	if (povcount != pov[0][x])
		return (0);
	max = 0;
	povcount = 0;
	while (y > 0)
	{
		y--;
		checkpovcount(grid[y][x], &max, &povcount);
	}
	if (povcount != pov[1][x])
		return (0);
	return (1);
}

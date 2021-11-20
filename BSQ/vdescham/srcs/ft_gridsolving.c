/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gridsolving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:47:08 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/24 21:47:10 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		ft_isexpandable(char **grid, int i, int j, int k)
{
	int l;

	l = 0;
	while (l <= k)
	{
		if (grid[i + l][j + k] == g_chars->obstacle
			|| grid[i + k][j + l] == g_chars->obstacle)
			return (0);
		l++;
	}
	return (1);
}

int		ft_maxexpand(char **grid, int i, int j)
{
	int k;

	k = 1;
	while (i + k < g_height && j + k < g_width
		&& ft_isexpandable(grid, i, j, k))
		k++;
	return (k);
}

void	ft_fillgrid(char **grid, int imax, int jmax, int max)
{
	int		i;
	int		j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			grid[imax + i][jmax + j] = g_chars->full;
			j++;
		}
		i++;
	}
}

void	ft_solvegrid(char **grid)
{
	int i;
	int j;
	int max;
	int imax;
	int jmax;

	i = 0;
	max = 0;
	while (i < g_height - max)
	{
		j = 0;
		while (j < g_width - max)
		{
			if (grid[i][j] == g_chars->empty && ft_maxexpand(grid, i, j) > max)
			{
				max = ft_maxexpand(grid, i, j);
				imax = i;
				jmax = j;
			}
			j++;
		}
		i++;
	}
	if (max > 0)
		ft_fillgrid(grid, imax, jmax, max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:33:16 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/17 01:43:37 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		placequeen(int grid[10], int y, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (grid[i] == y || x - i == y - grid[i] || i - x == y - grid[i])
			return (0);
		i++;
	}
	return (1);
}

void	print_soluce(int grid[10], int i)
{
	while (i < 10)
	{
		ft_putchar(grid[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int		ft_backtracking(int grid[10], int x, int y, int *soluce)
{
	while (y < 10)
	{
		if (placequeen(grid, y, x))
		{
			grid[x] = y;
			if (x == 9)
			{
				print_soluce(grid, 0);
				return (*soluce + 1);
			}
			*soluce = ft_backtracking(grid, x + 1, 0, soluce);
		}
		y++;
	}
	return (*soluce);
}

int		ft_ten_queens_puzzle(void)
{
	int grid[10];
	int soluce;

	soluce = 0;
	ft_backtracking(grid, 0, 0, &soluce);
	return (soluce);
}

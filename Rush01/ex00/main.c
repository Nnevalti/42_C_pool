/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:32:52 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/14 12:33:42 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_createpov(char *data, int (*pov)[4])
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (data[i] != '\0' && j < 4)
	{
		if(data[i] >= '0' && data[i] <= '9' && count < 4)
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

int		checkrow(int (*pov)[4], int (*grid)[4], int y, int x)
{
	int max;
	int povcount;

	max = 0;
	povcount = 0;
	while (x < 4)
	{
		if (grid[y][x] > max)
		{
			max = grid[y][x];
			povcount++;
		}
		x++;
	}
	if (povcount != pov[2][y])
		return (0);
	max = 0;
	povcount = 0;
	while (x > 0)
	{
		x--;
		if (grid[y][x] > max)
		{
			max = grid[y][x];
			povcount++;
		}
	}
	if (povcount != pov[3][y])
		// return (0);
		printf("povcount %d\n", povcount);
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
		if (grid[y][x] > max)
		{
			max = grid[y][x];
			povcount++;
		}
		y++;
	}
	if (povcount != pov[0][y])
		return (0);
	max = 0;
	povcount = 0;
	while (y > 0)
	{
		y--;
		if (grid[y][x] > max)
		{
			max = grid[y][x];
			povcount++;
		}
	}
	if (povcount != pov[1][y])
		return (0);
	return (1);
}

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
	if (y == 4 && checkcol(pov, grid, 3, 3))
{
		printf("Atteind");
		return(1);
}
printf("\n\n%d\n\n", y);
	if (x == 4 && checkrow(pov, grid, y, 0))
	{
			if(ft_backtracking(pov, grid, y + 1, 0) == 1)
				return (1);
	}
	while (nb < 4)
	{
		nb++;
		if (placenb(nb, grid, x, y) && x < 4 && y < 4)
		{
			grid[y][x] = nb;
			/* lol */
			printf("\ngrid :\n\n");
			printf("%d", y);
			for (int t = 0; t < 4; t++)
			{
				for (int u = 0; u < 4; u++)
				{
					printf("%d ", grid[t][u]);
				}
				printf("\n");
			}
			/* lel */

			 if (ft_backtracking(pov, grid, y, x + 1) == 1)
			 			return (1);
				grid[y][x] = 0;
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int pov[4][4];
	int grid[4][4];
	int success;

	success = 0;
	(void)argc;
	if (!argv[1])
		write(1, "ERREUR", 6);
	ft_createpov(argv[1], pov);
	ft_creategrid(grid);
	/*ft_prefill(grid, pov, 4);   In pause for the moment*/
	ft_backtracking(pov, grid, 0, 0);

	/* DELETE THIS PART before last push*/
	printf("pov tab :\n");
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			printf("%d ", pov[a][b]);
		}
		printf("\n");
	}

	printf("\n\n");
	printf("grid final :\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

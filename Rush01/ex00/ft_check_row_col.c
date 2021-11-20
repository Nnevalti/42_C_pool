#include "header.h"

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
		if (grid[y][x] > max)
		{
			max = grid[y][x];
			povcount++;
		}
		y++;
	}
	if (povcount != pov[0][x])
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
	if (povcount != pov[1][x])
		return (0);
	return (1);
}


/*void ft_prefill(int (*grid)[4], int (*pov)[4], int size)
{
	int i;
	int j;
	int prefill;
	
	i = 0;
	j = 0;
	prefill = 1;

	while (i < 4)
	{
		while(j < 4)
		{
			if (pov[i][j] == size)
			{
				if (i == 0)
				{
					j = 0;
					while (j < 4)
					{
						grid[i][j] = prefill;
						prefill++;
						j++;
					}
				}
				if (i == 1)
				{
					j = 4;
					while (j > 0)
					{
						j--;
						grid[i][j] = prefill;
						prefill++;
					}
					
				}
				if (i == 2)
				{
					j = 0;
					while (j < 4)
					{
						grid[i][j] = prefill;
						prefill++;
						j++;
					}
				}
				if (i == 3)
				{
					j = 4;

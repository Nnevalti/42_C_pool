/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 00:19:58 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/09 16:13:13 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab_value(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0' + tab[i]);
		i++;
	}
	if (tab[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_reccur(int *tab, int n, int i)
{
	int j;

	while (tab[i] <= 10 - n + i)
	{
		if (i < n - 1)
		{
			ft_reccur(tab, n, i + 1);
			tab[i]++;
			j = i;
			while (j < n)
			{
				tab[j + 1] = tab[j] + 1;
				j++;
			}
		}
		if (i == n - 1)
		{
			ft_print_tab_value(tab, n);
			tab[i]++;
		}
	}
}

void	ft_print_combn(int n)
{
	int i;
	int tab[n];

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	ft_reccur(tab, n, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 01:32:03 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/15 17:52:01 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_twicechar(char c, char *base, int i)
{
	int j;

	j = i + 1;
	while (base[j] != '\0')
	{
		if (c == base[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_printnbr(long nbr, char *base, int size)
{
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr >= size)
	{
		ft_printnbr(nbr / size, base, size);
		ft_putchar(base[nbr % size]);
	}
	else
		write(1, (base + nbr), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	n;

	i = 0;
	n = nbr;
	if (base[0] == '\0' || base[1] == '\0')
	{
		return ;
	}
	while (base[i] != '\0')
	{
		if (base[i] == 43 || base[i] == 45 || base[i] <= 32
				|| ft_twicechar(base[i], base, i))
		{
			return ;
		}
		i++;
	}
	ft_printnbr(n, base, i);
}

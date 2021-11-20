/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:37:32 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/22 21:35:28 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (*(str + i) == 32 || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	while (*(str + i) == 43 || *(str + i) == 45)
	{
		if (*(str + i) == 45)
			sign *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		nb = (nb * 10) + *(str + i) - '0';
		i++;
	}
	nb *= sign;
	return (nb);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
	else
		ft_putchar('0' + n);
}

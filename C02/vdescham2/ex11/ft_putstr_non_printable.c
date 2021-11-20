/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:10:23 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/15 23:43:35 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*tab;
	int		i;

	i = 0;
	tab = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] < 32 && str[i] > 127)
		{
			ft_putchar('\\');
			ft_putchar(tab[str[i] / 16]);
			ft_putchar(tab[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

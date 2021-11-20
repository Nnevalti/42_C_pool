/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:10:23 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/22 16:55:46 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*tab;
	unsigned char	*u_str;
	int				i;

	i = 0;
	u_str = (unsigned char*)str;
	tab = "0123456789abcdef";
	while (u_str[i])
	{
		if (u_str[i] < 32 && u_str[i] > 126)
		{
			ft_putchar('\\');
			ft_putchar(tab[u_str[i] / 16]);
			ft_putchar(tab[u_str[i] % 16]);
		}
		else
			ft_putchar(u_str[i]);
		i++;
	}
}

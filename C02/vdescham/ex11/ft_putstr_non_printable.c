/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:10:23 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/10 17:53:48 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char *tab;

	tab = "0123456789ABCDEF";
	while (*str != '\0')
	{
		if (*str < 32)
		{
			ft_putchar('\\');
			ft_putchar(tab[*str / 16]);
			ft_putchar(tab[*str % 16]);
		}
		else
			ft_putchar(*str);
		str++;
	}
}

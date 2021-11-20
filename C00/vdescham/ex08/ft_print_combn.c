/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 00:19:58 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/07 14:45:35 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	int tab[n];
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	
	i = n - 1;
	while(tab[i] <= 10 - n + i)
	{
		tab[i]++;
		j = 0;
		while(j < n)
		{
			write(1,'0' + tab[j],1);
			j++;
		}
		write(1, ", ", 2);
	}
	
	i--;

}

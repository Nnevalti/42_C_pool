/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:42:11 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/11 17:19:19 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (tab[j] < tab[i])
			{
				tab[i] = tab[i] + tab[j];
				tab[j] = tab[i] - tab[j];
				tab[i] = tab[i] - tab[j];
			}
			j++;
		}
		i++;
	}
}

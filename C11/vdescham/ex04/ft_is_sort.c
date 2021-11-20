/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:08:40 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 15:49:19 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		which_sort(int *tab, int length)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < length - 1)
	{
		if (tab[i] > tab[i + 1])
			y = 1;
		else if (tab[i] < tab[i + 1])
			y = -1;
		i++;
	}
	return (y);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	if (length == 1)
		return (1);
	y = which_sort(tab, length);
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (y == 1 && (*f)(tab[i], tab[j]) < 0)
				return (0);
			if (y == -1 && (*f)(tab[i], tab[j]) > 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

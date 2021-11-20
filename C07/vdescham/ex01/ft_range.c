/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:51:35 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/22 23:35:53 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int range;
	int i;

	range = 0;
	i = 0;
	if (min >= max)
		return (0);
	else
		range = max - min;
	tab = malloc(sizeof(int) * range);
	if (!tab)
		return (0);
	while (i < range)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

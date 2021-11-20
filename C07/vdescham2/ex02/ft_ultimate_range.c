/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:03:24 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/22 23:36:12 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int valuerange;
	int i;

	valuerange = 0;
	i = 0;
	if (min >= max)
		return (0);
	else
		valuerange = max - min;
	*range = malloc(sizeof(int) * valuerange);
	if (!*range)
		return (-1);
	while (i < valuerange)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (valuerange);
}

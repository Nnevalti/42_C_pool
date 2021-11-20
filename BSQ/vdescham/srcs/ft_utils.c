/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:47:43 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/24 21:47:44 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		ft_atoi(char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}


void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_display(char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_height)
	{
		j = 0;
		while (j < g_width)
		{
			write(1, &grid[i][j], 1);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

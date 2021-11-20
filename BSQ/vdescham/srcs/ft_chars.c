/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:51:08 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/24 21:51:10 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	ft_set_string(char *str)
{
	if (!(g_chars = (t_chars *)malloc(sizeof(t_chars))))
	{
		g_chars = NULL;
		return ;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	g_chars->empty = *str;
	str++;
	g_chars->obstacle = *str;
	str++;
	g_chars->full = *str;
	str++;
	if (*str || !g_chars->empty || !g_chars->obstacle || !g_chars->full)
	{
		free(g_chars);
		g_chars = NULL;
	}
}

int		ft_is_char(char c)
{
	return (g_chars->empty == c || g_chars->obstacle == c);
}

int		ft_check_string(void)
{
	return (g_chars->empty != g_chars->obstacle
			&& g_chars->obstacle != g_chars->full
			&& g_chars->empty != g_chars->full);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 10:31:52 by rarihet           #+#    #+#             */
/*   Updated: 2019/07/21 23:08:19 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_len(str));
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s2[i] == '\0')
			return (s1[i]);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] != '\0')
		return (s2[i] * -1);
	return (0);
}

int		manage_millions(int *i, int three_packs, t_list *list)
{
	if (*i == 0 && list->nbr_len % three_packs == 0)
		three_packs--;
	if (check_packs(list->nbr[*i], list->nbr[*i + 1], list->nbr[*i + 2]) == 3)
	{
		three_packs--;
		*i = *i + 3;
	}
	return (three_packs);
}

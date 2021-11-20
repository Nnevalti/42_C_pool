/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:47:36 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/24 21:47:37 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int		ft_get_nb_lines(char *str)
{
	int		nb_lines;

	nb_lines = 0;
	while (*str)
	{
		while (*str == '\n')
			str++;
		if (*str != '\0')
			nb_lines++;
		while (*str && *str != '\n')
			str++;
	}
	return (nb_lines);
}

char	*ft_get_next_line(char *str)
{
	int		nb_chars;
	char	*next_line;
	int		i;

	nb_chars = 0;
	while (str[nb_chars] && str[nb_chars] != '\n')
		nb_chars++;
	next_line = (char *)malloc((nb_chars + 1) * sizeof(char));
	i = 0;
	while (i < nb_chars)
	{
		next_line[i] = str[i];
		i++;
	}
	next_line[nb_chars] = '\0';
	return (next_line);
}

char	**ft_split(char *str)
{
	int		nb_lines;
	char	**tab;
	int		i;

	nb_lines = ft_get_nb_lines(str);
	tab = (char **)malloc((nb_lines + 1) * sizeof(char *));
	i = 0;
	while (i < nb_lines)
	{
		while (*str == '\n')
			str++;
		if (*str != '\0')
			tab[i] = ft_get_next_line(str);
		while (*str && *str != '\n')
			str++;
		i++;
	}
	tab[nb_lines] = NULL;
	return (tab);
}

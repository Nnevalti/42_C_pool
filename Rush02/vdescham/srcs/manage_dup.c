/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:16:03 by rarihet           #+#    #+#             */
/*   Updated: 2019/07/21 23:13:54 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

char	*ft_strdupcat(char *str, char *dest)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	if ((new = malloc(sizeof(char) * (ft_len(str) + ft_len(dest) + 1))) == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	j = 0;
	while (dest[j] != '\0')
	{
		new[i + j] = dest[j];
		j++;
	}
	new[i + j] = '\0';
	free(str);
	return (new);
}

char	*ft_strdup(char *str, char *sep, int min, int max)
{
	int		i;
	int		j;
	char	*res;

	if ((res = malloc(sizeof(char) * (max - min + 1))) == 0)
		return (NULL);
	i = 0;
	while (str[min + i] != '\0' && min + i < max)
	{
		j = -1;
		while (sep[++j] != '\0')
			if (str[i + min] == sep[j])
				break ;
		if (sep[j] == '\0')
		{
			res[i] = str[min + i];
			i++;
		}
		else
			min++;
	}
	if (i == 0)
		return (NULL);
	res[i] = '\0';
	return (res);
}

char	*open_file(char *name, int end, int fd, int size)
{
	char	*str;
	char	buff[1000];

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (NULL);
	}
	if ((str = malloc(sizeof(char) * 1)) == 0)
		return (NULL);
	str[0] = '\0';
	while ((size = read(fd, buff, 1000)) != 0)
	{
		if (size == -1)
		{
			write(1, "Cannot read file.\n", 18);
			return (NULL);
		}
		end += size;
		buff[size] = '\0';
		str = ft_strdupcat(str, buff);
		str[end] = '\0';
	}
	str[end] = '\0';
	return (str);
}

int		manage_exeption(t_list *list, char *nbr)
{
	if (ft_strcmp(nbr, "0") == 0)
	{
		while (list)
		{
			if (ft_strcmp(list->nb, nbr) == 0)
			{
				ft_putstr(list->name);
				ft_putchar('\n');
				return (1);
			}
			list = list->next;
		}
	}
	return (0);
}

void	free_list(t_list *list)
{
	while (list != NULL)
	{
		free(list);
		list = list->next;
	}
	free(list);
}

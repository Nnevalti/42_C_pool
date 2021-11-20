/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:30:25 by rarihet           #+#    #+#             */
/*   Updated: 2019/07/21 23:18:15 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

char		*find_num(char *str, int *i)
{
	int		keep_i;
	int		j;
	char	*num;

	keep_i = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
		*i = *i + 1;
	if ((num = malloc(sizeof(char) * (*i + 1))) == 0)
		return (NULL);
	*i = keep_i;
	j = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num[j] = str[*i];
		*i = *i + 1;
		j++;
	}
	num[j] = '\0';
	return (num);
}

char		*find_name(char *str, int *i)
{
	int		keep_i;
	int		j;
	char	*name;

	keep_i = *i;
	while (str[keep_i] >= 32 && str[keep_i] <= 126)
		keep_i++;
	if ((name = malloc(sizeof(char) * (keep_i + 1))) == 0)
		return (NULL);
	j = 0;
	while (str[*i] != '\0' && str[*i] != '\n' && \
str[*i] >= 32 && str[*i] <= 126)
	{
		name[j] = str[*i];
		*i = *i + 1;
		j++;
	}
	name[j] = '\0';
	return (name);
}

t_list		*fill_list(t_list *list, char *str)
{
	int		i;
	char	*nb;
	char	*name;
	t_list	*first;

	i = 0;
	first = list;
	while (str[i] != '\0')
	{
		nb = find_num(str, &i);
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == ':'))
			i++;
		if (str[i] == '\0')
			break ;
		name = find_name(str, &i);
		list->nb = nb;
		list->name = name;
		if ((list->next = malloc(sizeof(t_list))) == 0)
			return (NULL);
		list = list->next;
		i++;
	}
	list = NULL;
	list = first;
	return (list);
}

void		manage_file(char *name, char *dico)
{
	char	*str;
	t_list	*list;
	int		i;

	if ((list = malloc(sizeof(t_list))) == 0)
		return ;
	if ((str = open_file(dico, 0, 0, 0)) == NULL)
		return ;
	i = 0;
	list = fill_list(list, str);
	if (manage_err(list, name) == 1)
	{
		write(1, "Error\n", 6);
		return ;
	}
	while (name[0] == '0' && name[1] != '\0')
		name = name + 1;
	list->nbr = name;
	print_str(list, name, 0);
	free_list(list);
}

int			main(int ac, char **av)
{
	if (ac == 2)
		manage_file(av[1], "numbers.dict");
	else if (ac == 3)
		manage_file(av[2], av[1]);
	else
		write(1, "Error\n", 6);
	return (0);
}

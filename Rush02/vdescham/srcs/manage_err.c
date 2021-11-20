/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shanein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:47:02 by shanein           #+#    #+#             */
/*   Updated: 2019/07/21 21:10:23 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

int		manage_nb(char *nb)
{
	int i;

	i = 0;
	while (nb[i] != '\0')
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int		manage_name(char *name)
{
	int i;

	i = 0;
	while (name[i] != '\0')
	{
		if (!(name[i] >= 32 && name[i] <= 126))
			return (1);
		i++;
	}
	return (0);
}

int		manage_double(t_list *list)
{
	t_list *tmp;

	if (list->name == NULL || list->name[0] == '\0')
		return (0);
	tmp = list->next;
	while (tmp->name != NULL)
	{
		if (ft_strcmp(list->name, tmp->name) == 0)
			return (1);
		if (ft_strcmp(list->nb, tmp->nb) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		manage_err(t_list *list, char *name)
{
	int i;

	while (list->name != NULL)
	{
		if (manage_nb(list->nb) == 1)
			return (1);
		if (manage_name(list->name) == 1)
			return (1);
		if (manage_double(list) == 1)
			return (1);
		list = list->next;
	}
	i = 0;
	while (name[i])
	{
		if (!('0' <= name[i] && name[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

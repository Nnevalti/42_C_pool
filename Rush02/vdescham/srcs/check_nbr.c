/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:47:12 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/21 23:08:41 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

int		ft_units(t_list *list, char nb)
{
	char unit[2];

	if (nb == '0')
		return (0);
	unit[0] = nb;
	unit[1] = '\0';
	while (list)
	{
		if (ft_strcmp(list->nb, unit) == 0)
		{
			ft_putstr(list->name);
			return (1);
		}
		list = list->next;
	}
	return (1);
}

int		ft_tens(t_list *list, char dec, char uni)
{
	char	tens[3];
	int		isten;

	tens[0] = dec;
	isten = 1;
	if (dec == '1' || uni == '0')
	{
		tens[1] = uni;
		isten = 2;
	}
	else
		tens[1] = '0';
	tens[2] = '\0';
	while (list)
	{
		if (ft_strcmp(list->nb, tens) == 0)
		{
			ft_putstr(list->name);
			break ;
		}
		list = list->next;
	}
	return (isten);
}

int		ft_hundreds(t_list *list, char cen, char dec, char un)
{
	int		i;

	if ((i = ft_units(list, cen)) != 0)
		ft_putchar(' ');
	i += check_packs(cen, dec, un);
	while (list != NULL)
	{
		if (ft_strcmp(list->nb, "100") == 0)
		{
			ft_putstr(list->name);
			break ;
		}
		list = list->next;
	}
	return (i);
}

char	*create_power(int packs)
{
	char	*nbr;
	int		i;
	int		j;

	if (!(nbr = malloc(sizeof(char) * ((3 * packs) + 1))))
		return (0);
	nbr[0] = '1';
	i = 1;
	while (packs > 0)
	{
		j = 0;
		while (j < 3)
		{
			nbr[i] = '0';
			i++;
			j++;
		}
		packs--;
	}
	nbr[i] = '\0';
	return (nbr);
}

int		manage_power(t_list *list, int packs, char *nb, int i)
{
	char *nbr;

	if (packs <= 0)
		return (0);
	nbr = create_power(packs);
	while (list != NULL)
	{
		if (ft_strcmp(list->nb, nbr) == 0)
		{
			ft_putstr(list->name);
			if (check_packs(nb[i], nb[i + 1], nb[i + 2]) != 3)
				write(1, " ", 1);
			break ;
		}
		list = list->next;
	}
	free(nbr);
	return (0);
}

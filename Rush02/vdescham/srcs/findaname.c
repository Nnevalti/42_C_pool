/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findaname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:18:30 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/21 23:06:24 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

int		manage_first_nb(t_list *list, char *nbr, int three_packs)
{
	int dec_nb;
	int i;
	int ret;

	i = 0;
	dec_nb = list->nbr_len % 3;
	ret = dec_nb;
	while (dec_nb > 0)
	{
		if (dec_nb == 2)
		{
			dec_nb -= ft_tens(list, nbr[i], nbr[i + 1]);
			i++;
		}
		else if (dec_nb == 1)
			dec_nb -= ft_units(list, nbr[i]);
		if (three_packs >= 0 && dec_nb >= 1)
			ft_putchar(' ');
	}
	if (ret > 0 && list->nbr_len > 3)
		ft_putchar(' ');
	else if (ret > 0 && three_packs > 0)
		ft_putchar('\n');
	return (ret);
}

int		check_packs(char cen, char dec, char un)
{
	if (cen == '0' && dec == '0' && un == '0')
		return (3);
	else if (dec == '0' && un == '0')
		return (2);
	else if (dec == '0')
		return (1);
	return (0);
}

int		manage_packs(t_list *list, char *nbr, int i)
{
	int j;
	int k;

	k = i;
	j = check_packs(nbr[i], nbr[i + 1], nbr[i + 2]);
	if (j < 3)
		j = 0;
	else
		return (i + 3);
	while (j < 3 && nbr[i] != '\0')
	{
		if (j == 0)
			j += ft_hundreds(list, nbr[i], nbr[i + 1], nbr[i + 2]);
		else if (j == 1)
		{
			j += ft_tens(list, nbr[i], nbr[i + 1]);
		}
		else if (j == 2)
			j += ft_units(list, nbr[i]);
		if (j > 0 && j <= 2)
			ft_putchar(' ');
		i = j + k;
	}
	return (i);
}

void	print_str(t_list *list, char *nbr, int i)
{
	int three_packs;

	if (manage_exeption(list, nbr) == 1)
		return ;
	if ((list->nbr_len = ft_len(nbr)) > 12)
	{
		write(1, "Error\n", 6);
		return ;
	}
	three_packs = list->nbr_len / 3;
	i = manage_first_nb(list, nbr, three_packs);
	if (i > 0 && list->nbr_len - 4 >= 0)
	{
		manage_power(list, three_packs, nbr, i);
		three_packs--;
	}
	three_packs = manage_millions(&i, three_packs, list);
	display_num(i, three_packs, list);
}

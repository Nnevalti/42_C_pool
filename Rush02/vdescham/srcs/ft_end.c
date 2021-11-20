/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:53:20 by rarihet           #+#    #+#             */
/*   Updated: 2019/07/21 23:06:42 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

void	display_num(int i, int three_packs, t_list *list)
{
	while (three_packs >= 0 && i < list->nbr_len)
	{
		i = manage_packs(list, list->nbr, i);
		if (i < list->nbr_len)
			ft_putchar(' ');
		manage_power(list, three_packs, list->nbr, i);
		three_packs--;
	}
	if (i >= list->nbr_len)
		ft_putchar('\n');
}

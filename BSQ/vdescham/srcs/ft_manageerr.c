/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageerr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:47:23 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/24 21:47:24 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	ft_puterr(char *str)
{
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
}

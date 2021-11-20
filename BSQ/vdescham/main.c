/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:29:39 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/24 21:29:47 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int ac, char **av)
{
	int		i;
	char	**grid;

	if (ac < 2)
	{
		grid = ft_parse_stdin();
		if (!grid)
			return (1);
		ft_launch(grid);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		grid = ft_parse(av[i]);
		if (grid)
			ft_launch(grid);
		i++;
		if (i < ac)
			ft_putstr("\n");
	}
	return (0);
}

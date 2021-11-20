/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:27:36 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 16:59:54 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

t_operator	*create_struct(void)
{
	static t_operator op[5];

	op[0].operator = '+';
	op[0].function = add;
	op[1].operator = '-';
	op[1].function = sub;
	op[2].operator = '/';
	op[2].function = div;
	op[3].operator = '*';
	op[3].function = mul;
	op[4].operator = '%';
	op[4].function = mod;
	return (op);
}

int			is_operator(t_operator *op, char c)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (c == op[i].operator)
			return (1);
		i++;
	}
	ft_putstr("0\n");
	return (0);
}

int			find_function(t_operator *op, char c, int a, int b)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (c == op[i].operator)
		{
			return (op[i].function(a, b));
		}
		i++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	int			result;
	t_operator	*op;

	if (ac != 4)
		return (0);
	if (av[2][1])
	{
		ft_putstr("0\n");
		return (0);
	}
	op = create_struct();
	if (!is_operator(op, av[2][0]))
		return (0);
	if (ft_atoi(av[3]) == 0 && (av[2][0] == '/' || av[2][0] == '%'))
	{
		if (av[2][0] == '/')
			ft_putstr("Stop : division by zero\n");
		else if (av[2][0] == '%')
			ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	result = find_function(op, av[2][0], ft_atoi(av[1]), ft_atoi(av[3]));
	ft_putnbr(result);
	ft_putchar('\n');
}

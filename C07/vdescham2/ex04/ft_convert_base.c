/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:37:10 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 18:39:08 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_rev_char_tab();
int		resultlen();

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		verif_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j]
					|| base[i] == 43 || base[i] == 45
					|| base[j] == 43 || base[j] == 45
					|| base[i] <= 32 || base[j] <= 32)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_rebase_from(char *str, char *base, int i, int sign)
{
	long	nb;
	int		j;
	int		base_len;

	base_len = ft_strlen(base);
	nb = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == base[j])
		{
			nb = (nb * base_len) + j;
			i++;
			j = 0;
		}
		else
			j++;
		if (base[j] == '\0')
			return (nb * sign);
	}
	return (nb * sign);
}

char	*ft_rebase_to(long nbr, char *base, int size, int i)
{
	char	*result;
	int		mallocsize;

	if (nbr < 0)
	{
		nbr *= -1;
		mallocsize = resultlen(nbr, size);
		result = malloc(sizeof(char) * mallocsize + 2);
		result[mallocsize] = '-';
		result[mallocsize + 1] = '\0';
	}
	else
	{
		mallocsize = resultlen(nbr, size);
		result = malloc(sizeof(char) * mallocsize + 1);
		result[mallocsize] = '\0';
	}
	while (nbr >= size)
	{
		result[i] = base[nbr % size];
		nbr = nbr / size;
		i++;
	}
	result[i] = base[nbr % size];
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		sign;
	long	nb;
	char	*result;

	nb = 0;
	i = 0;
	sign = 1;
	result = NULL;
	if (verif_base(base_to) || verif_base(base_from) || !nbr)
		return (result);
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == 43 || nbr[i] == 45)
	{
		if (nbr[i] == 45)
			sign *= -1;
		i++;
	}
	nb = ft_rebase_from(nbr, base_from, i, sign);
	result = ft_rebase_to(nb, base_to, ft_strlen(base_to), 0);
	ft_rev_char_tab(result, ft_strlen(result));
	return (result);
}

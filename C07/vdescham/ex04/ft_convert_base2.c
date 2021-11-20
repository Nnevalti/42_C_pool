/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:01:09 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/21 18:57:27 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_char_tab(char *tab, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

int		resultlen(long nb, int base_size)
{
	int i;

	i = 0;
	while (nb >= base_size)
	{
		nb = nb / base_size;
		i++;
	}
	return (i + 1);
}

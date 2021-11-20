/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:05:52 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 22:08:46 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		verif_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == 32 
					|| base[i] == 43 || base[i] == 45
					|| (base[i] >= 9 && base[i] <= 13))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_rebase(char *str, char *base, int i, int sign)
{
	int nb;
	int j;
	int base_len;

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
			return (nb *= sign);
	}
	return (nb *= sign);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	if (!base[0] || !base[1] || verif_base(base))
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	return (ft_rebase(str, base, i, sign));
}

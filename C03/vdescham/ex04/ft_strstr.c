/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 03:02:42 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/15 20:07:16 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && str[i + j])
		{
			j++;
			if (!to_find[j])
				return (&str[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}

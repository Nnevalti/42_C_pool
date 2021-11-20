/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 00:17:35 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/10 14:28:41 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (65 > *(str + i) || *(str + i) > 122
				|| (90 < *(str + i) && *(str + i) < 97))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
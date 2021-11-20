/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:45:23 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/10 14:30:15 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char str)
{
	if ((65 <= str && str <= 90) || (97 <= str && str <= 122))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char *pointer;

	pointer = str;
	while (*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
		{
			*str += 32;
		}
		if (!ft_str_is_alpha(*(str - 1))
					&& !(48 < *(str - 1) && *(str - 1) < 57)
						&& !(48 < *str && *str < 57)
							&& ft_str_is_alpha(*str))
		{
			*str -= 32;
		}
		str++;
	}
	return (pointer);
}

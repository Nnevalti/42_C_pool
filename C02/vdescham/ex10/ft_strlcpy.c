/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:18:11 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/10 14:04:54 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		if (i < size - 1)
		{
			*(dest + i) = *(src + i);
		}
		i++;
	}
	*(dest + i) = '\0';
	return (i);
}

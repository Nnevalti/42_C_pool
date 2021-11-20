/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:40:18 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/09 02:59:32 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (*(dest + i) != '\0')
		i++;
	j = 0;
	while (*(src + j) != '\0' && j < nb)
	{
		*(dest + i) = *(src + j);
		j++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

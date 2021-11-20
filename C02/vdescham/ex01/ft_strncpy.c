/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 00:13:43 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/10 17:53:04 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (*src != '\0')
		{
			*(dest + i) = *src;
			src++;
		}
		else
			*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

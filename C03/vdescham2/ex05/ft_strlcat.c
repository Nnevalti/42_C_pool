/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:25:19 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/15 20:50:43 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strncat(char *dest, char *src, unsigned int nb)
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (size + len_src);
	if (len_src < size - len_dest)
		ft_strncat(dest, src, len_src + 1);
	else
	{
		ft_strncat(dest, src, size - len_dest - 1);
		dest[size - 1] = '\0';
	}
	return (len_dest + len_src);
}

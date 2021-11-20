/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:39:38 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/22 23:36:57 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_total_len(int size, char **strs, char *sep)
{
	int i;
	int total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len);
}

void	fillresult(int size, char **strs, char *result, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			result[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			result[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*result;

	total_len = ft_total_len(size, strs, sep);
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	fillresult(size, strs, result, sep);
	return (result);
}

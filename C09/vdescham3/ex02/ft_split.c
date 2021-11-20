/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:20:03 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/23 23:54:02 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ischarset(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ischarset(charset, str[i]) && str[i])
			i++;
		if (!ischarset(charset, str[i]) && str[i])
			count++;
		while (!ischarset(charset, str[i]) && str[i])
			i++;
	}
	return (count);
}

void	words_length(char **result, char *str, char *charset)
{
	int i;
	int j;
	int word_len;

	i = 0;
	j = 0;
	while (str[i])
	{
		word_len = 0;
		while (ischarset(charset, str[i]))
			i++;
		while (!ischarset(charset, str[i]) && str[i])
		{
			word_len++;
			i++;
		}
		result[j] = (char*)malloc(sizeof(char) * word_len + 1);
		if (!result[j] || !str[i])
			return ;
		j++;
	}
}

void	fillresult(char **result, char *str, char *charset, int nb_words)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (str[i] && j < nb_words)
	{
		k = 0;
		while (ischarset(charset, str[i]))
			i++;
		while (!ischarset(charset, str[i]) && str[i])
		{
			result[j][k] = str[i];
			k++;
			i++;
		}
		result[j][k] = '\0';
		j++;
	}
	result[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		count_words;
	char	**result;

	count_words = ft_count_words(str, charset);
	result = (char**)malloc(sizeof(char*) * count_words + 1);
	words_length(result, str, charset);
	fillresult(result, str, charset, count_words);
	return (result);
}

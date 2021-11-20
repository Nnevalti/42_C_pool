/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:27:18 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 16:51:18 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(tab) - 1;
	printf("%d\n", ft_strlen(tab));
	while (i > 0)
	{
		j = 0;
		while (j < i - 1)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

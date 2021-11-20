/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:19:58 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/10 16:45:46 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	char test[] = "";

	test = addr;
	i = 0;
	while (addr)
	{
		write(1, (*(test + i) >> 4) & 0xf, 1);
		i++;
	}

}

int main (void)
{
	char test[] = "Ceci est un test";
	ft_print_memory(test, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:29:34 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/22 16:40:14 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_addr_display(char *addr)
{
	char			*base;
	unsigned long	memory_addr;

	memory_addr = (unsigned long)addr;
	base = "0123456789abcdef";
	ft_putchar(base[(memory_addr / 131072) % 16]);
	ft_putchar(base[(memory_addr / 65536) % 16]);
	ft_putchar(base[(memory_addr / 32768) % 16]);
	ft_putchar(base[(memory_addr / 16384) % 16]);
	ft_putchar(base[(memory_addr / 8192) % 16]);
	ft_putchar(base[(memory_addr / 4096) % 16]);
	ft_putchar(base[(memory_addr / 2048) % 16]);
	ft_putchar(base[(memory_addr / 1024) % 16]);
	ft_putchar(base[(memory_addr / 512) % 16]);
	ft_putchar(base[(memory_addr / 256) % 16]);
	ft_putchar(base[(memory_addr / 128) % 16]);
	ft_putchar(base[(memory_addr / 64) % 16]);
	ft_putchar(base[(memory_addr / 32) % 16]);
	ft_putchar(base[(memory_addr / 16) % 16]);
	ft_putchar(base[memory_addr % 16]);
	write(1, ": ", 2);
}

void	ft_asciitohexa(char *asciivalue, int size)
{
	int		i;
	char	*base;

	i = 1;
	base = "0123456789abcdef";
	while (i < size + 1)
	{
		ft_putchar(base[(*asciivalue / 16) % 16]);
		ft_putchar(base[*asciivalue % 16]);
		if (i % 2 == 0)
			ft_putchar(' ');
		i++;
		asciivalue++;
	}
	while (i <= 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 0)
			ft_putchar(' ');
		i++;
	}
}

int		printstr(char *addr, int size)
{
	int i;

	i = 0;
	while (i < size && addr[i])
	{
		if (addr[i] >= 32 && addr[i] < 127)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
	return (i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*addr2;
	int		j;

	addr2 = (char*)addr;
	j = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			ft_addr_display(addr2);
			ft_asciitohexa(addr2, 16);
			j = printstr(addr2, 16);
			addr2 += 16;
			size -= j;
		}
		else if (size < 16)
		{
			ft_addr_display(addr2);
			ft_asciitohexa(addr2, size);
			j = printstr(addr2, size);
			size -= j;
		}
		ft_putchar('\n');
	}
	return (addr);
}

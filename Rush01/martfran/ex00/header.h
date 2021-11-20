/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:33:14 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/14 20:21:00 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>

void	ft_putchar(char c);
int		ft_createpov(char *data, int (*pov)[4]);
void	ft_creategrid(int (*grid)[4]);
void	ft_printgrid(int (*grid)[4]);
int		checkrow(int (*pov)[4], int (*grid)[4], int y, int x);
int		checkcol(int (*pov)[4], int (*grid)[4], int y, int x);
int		placenb(int nb, int (*grid)[4], int x, int y);
int		ft_backtracking(int (*pov)[4], int (*grid)[4], int y, int x);

#endif

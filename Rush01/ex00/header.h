#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
void ft_putchar(char c);
void	ft_createpov(char *data, int (*pov)[4]);
void	ft_creategrid(int (*grid)[4]);
int		checkrow(int (*pov)[4], int (*grid)[4], int y, int x);
int		checkcol(int (*pov)[4], int (*grid)[4], int y, int x);
int		placenb(int nb, int (*grid)[4], int x, int y);
int		ft_backtracking(int (*pov)[4], int (*grid)[4], int y, int x);

#endif

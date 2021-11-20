/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:20:31 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/22 22:04:59 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int				add(int a, int b);
int				sub(int a, int b);
int				div(int a, int b);
int				mul(int a, int b);
int				mod(int a, int b);
void			ft_putchar(char c);
int				ft_atoi(char *str);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);

typedef struct	s_operator
{

	char	operator;
	int		(*function)(int, int);

}				t_operator;

#endif

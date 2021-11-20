/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:59:22 by rarihet           #+#    #+#             */
/*   Updated: 2019/07/21 23:14:02 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	char			*nb;
	char			*name;
	int				nbr_len;
	char			*nbr;
	struct s_list	*next;
}				t_list;

int				manage_packs(t_list *list, char *nbr, int i);
int				manage_power(t_list *list, int packs, char *nb, int i);
void			display_num(int i, int three_packs, t_list *list);
int				manage_millions(int *i, int three_packs, t_list *list);
int				manage_err(t_list *list, char *name);
int				ft_len(char *str);
void			free_list(t_list *list);
int				manage_exeption(t_list *list, char *nbr);
void			ft_putstr(char *str);
void			ft_putchar(char c);
char			*open_file(char *name, int end, int fd, int size);
int				ft_strcmp(char *s1, char *s2);
int				ft_units(t_list *list, char nb);
int				ft_tens(t_list *list, char dec, char un);
int				ft_hundreds(t_list *list, char cen, char dec, char un);
int				manage_power(t_list *list, int packs, char *nbr, int i);
int				check_packs(char cen, char dec, char un);
void			print_str(t_list *list, char *nbr, int i);

#endif

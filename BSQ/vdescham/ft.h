/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:44:14 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/24 21:44:16 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 12000

typedef struct	s_chars
{
	char		empty;
	char		obstacle;
	char		full;
}				t_chars;

t_chars			*g_chars;
int				g_width;
int				g_height;

void			ft_putstr(char *str);
void			ft_puterr(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *str1, char *str2);
int				ft_atoi(char *str);

char			**ft_parse(char *path);
char			**ft_parse_stdin(void);

void			ft_set_string(char *str);
int				ft_is_char(char c);
int				ft_check_string(void);

void			ft_launch(char **grid);
void			ft_solvegrid(char **grid);
void			ft_display(char **grid);
void			ft_freegrid(char **grid);

#endif

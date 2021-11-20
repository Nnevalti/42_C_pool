/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:53:03 by vdescham          #+#    #+#             */
/*   Updated: 2019/07/25 22:53:06 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <libgen.h>
# define BUF_SIZE 524288

int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif

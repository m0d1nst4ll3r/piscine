/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:41:54 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/01 23:16:45 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define BUFSIZE 256
# define ERR_CANT_OPEN 1

# include <fnctl.h>
# include <unist.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

//	ft_hexdump_util.c
char	*hd_realloc(char *old, char byte);
int		hd_strcmp(char *s1, char *s2);
int		hd_strncmp(char *s1, char *s2, int n);
int		hd_strlen(char *str);
int		hd_open(char *file);

//	ft_hexdump_error.c
int		hd_err(int err, char *name, char *str);

#endif

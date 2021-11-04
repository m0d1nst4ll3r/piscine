/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:41:54 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/04 21:48:57 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define BUFSIZE 256
# define ERR_CANT_OPEN 1

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_fileinfo
{
	int		ac;
	int		argnum;
	int		canon;
	int		fd;
	int		skip;
	int		pos;
	char	*buf;
	char	*cur;
	int		remain;
	int		buflen;
}	t_fileinfo;

//	ft_hexdump_util.c
char	*hd_realloc(char *old, char byte, int len);
int		hd_strcmp(char *s1, char *s2);
int		hd_strncmp(char *s1, char *s2, int n);
int		hd_strlen(char *str);
int		hd_open(char *file);

//	ft_hexdump_util2.c
void	ft_putstr(char *str, int chan);
void	ft_putchar(char c);
void	hd_puthex(char h);
void	hd_putcharhex(char h);
void	init_data(t_fileinfo *data, int ac);

//	ft_hexdump_util3.c
void	hd_update(t_fileinfo *data);
int		hd_ceil(int n);

//	ft_hexdump_print.c
void	hd_print_mem(int pos, int canon);
void	hd_print(t_fileinfo *data);

//	ft_hexdump_error.c
int		hd_err(int err, char *name, char *str);

#endif

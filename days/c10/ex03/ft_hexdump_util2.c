/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:58:31 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/04 21:37:40 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putstr(char *str, int chan)
{
	while (*str)
		write(chan, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hd_puthex(char h)
{
	if (h < 10)
		h = h + '0';
	else
		h = h - 10 + 'a';
	write(1, &h, 1);
}

void	hd_putcharhex(char h)
{
	hd_puthex(h >> 4 & 0xf);
	hd_puthex(h & 0xf);
}

void	init_data(t_fileinfo *data, int ac)
{
	if (! data)
		return ;
	data->ac = ac;
	data->argnum = 1;
	data->canon = 0;
	data->fd = 0;
	data->skip = 0;
	data->pos = 0;
	data->buf = 0;
	data->buflen = 0;
	data->cur = 0;
}

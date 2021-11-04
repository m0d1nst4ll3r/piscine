/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:52:21 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/04 21:48:32 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	hd_print_mem(int pos, int canon)
{
	int		i;

	i = 3;
	while (i >= 0)
	{
		if (canon || i != 3)
			hd_puthex(pos >> (i * 8 + 4) & 0xf);
		hd_puthex(pos >> (i * 8) & 0xf);
		i--;
	}
}

static void	hd_print_bytes_canon(char *buf, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		hd_putcharhex(buf[i]);
		ft_putchar(' ');
		if (i % 8 == 7)
			ft_putchar(' ');
		i++;
	}
	while (i < 16)
	{
		ft_putstr("   ", 1);
		if (i % 8 == 7)
			ft_putchar(' ');
		i++;
	}
}

static void	hd_print_bytes_nocanon(char *buf, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		if (i % 2)
			hd_putcharhex(buf[i - 1]);
		else
			hd_putcharhex(buf[i + 1]);
		if (i % 2 && i != 15)
			ft_putchar(' ');
		i++;
	}
	if (limit % 2)
		hd_putcharhex(buf[i - 1]);
	while (i < 16)
	{
		ft_putstr("  ", 1);
		if (i % 2 && i < 15)
			ft_putchar(' ');
		i++;
	}
}

static void	hd_print_chars(char *buf, int limit)
{
	int	i;

	i = 0;
	ft_putchar('|');
	while (i < limit)
	{
		if (buf[i] <= 31 || buf[i] >= 127)
			ft_putchar('.');
		else
			ft_putchar(buf[i]);
		i++;
	}
	ft_putchar('|');
}

void	hd_print(t_fileinfo *data)
{
	hd_update(data);
	if (data->pos
		&& ! hd_strncmp(data->cur, data->cur - 16, hd_ceil(data->remain)))
	{
		if (! data->skip)
		{
			ft_putstr("*\n", 1);
			data->skip = 1;
		}
	}
	else
	{
		data->skip = 0;
		hd_print_mem(data->pos, data->canon);
		ft_putchar(' ');
		if (data->canon)
		{
			ft_putchar(' ');
			hd_print_bytes_canon(data->cur, hd_ceil(data->remain));
			hd_print_chars(data->cur, hd_ceil(data->remain));
		}
		else
			hd_print_bytes_nocanon(data->cur, hd_ceil(data->remain));
		ft_putstr("\n", 1);
	}
}

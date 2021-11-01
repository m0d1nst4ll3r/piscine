/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:52:21 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/01 23:16:54 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	hd_puthex(char h)
{
	if (h < 10)
		h = h + '0';
	else
		h = h - 10 + 'a';
	write(1, &h, 1);
}

void	hd_print_mem(long int pos, int canon)
{
	char	*pos_char;
	int		i;

	pos_char = (char *)pos;
	i = 7;
	if (canon)
		i = 8;
	while (i--)
		hd_puthex(*(pos_char++));
}

void	hd_print_bytes(char *bytes, int canon)
{
	int	i;

	i = 0;
	while (bytes[i] && i < 16)
	{
		if (canon)
			hd_puthex(bytes[i]);
		else

	}
	while (i < 16)
	{

	}
}

void	hd_print(char *bytes, int pos, int canon)
{
	if (po > 0 && hd_strlen(bytes + pos) >= 16
		&& hd_strncmp(bytes + pos, bytes + pos - 16, 16))
		hd_putstr("*", 1);
	else
	{
		hd_print_mem(pos, canon);
		if (canon)
			hd_putstr("  ");
		else
			hd_putstr(" ");
		hd_print_bytes(bytes + pos, canon);
		if (canon)
		{
			hd_putstr("|", 1);
			hd_print_chars(" ");
			hd_putstr("|", 1);
		}
	}
	hd_putstr("\n", 1);
}

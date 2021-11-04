/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_util3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:46:53 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/04 21:49:17 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	hd_update(t_fileinfo *data)
{
	data->cur = data->buf + data->pos;
	data->remain = data->buflen - data->pos;
}

int	hd_ceil(int n)
{
	if (n > 16)
		return (16);
	else
		return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:41:38 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/01 18:52:12 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static void	hd_err_open(char *name, char *file)
{
	ft_putstr(name, 2);
	ft_putstr(": ", 2);
	ft_putstr(file, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}

//	Display errors with tail's syntax
int	hd_err(int err, char *name, char *str)
{
	if (err == ERR_CANT_OPEN)
		ft_err_open(name, str);
	return (err);
}

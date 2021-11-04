/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:41:50 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/04 21:35:43 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static int	hd_read(t_fileinfo *data)
{
	int		size;
	int		i;
	char	buf[BUFSIZE];

	size = 1;
	while (size)
	{
		size = read(data->fd, buf, BUFSIZE);
		i = -1;
		while (++i < size)
		{
			data->buf = hd_realloc(data->buf, buf[i], data->buflen);
			if (! data->buf)
				return (1);
			data->buflen++;
		}
		while (data->buf && data->buflen - data->pos >= 16)
		{
			hd_print(data);
			data->pos += 16;
		}
	}
	return (0);
}

static void	end_file(t_fileinfo *data)
{
	if (data->buflen - data->pos)
	{
		hd_print(data);
		data->pos = data->buflen;
	}
	hd_print_mem(data->pos, data->canon);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	t_fileinfo	data;

	init_data(&data, ac);
	if (data.ac == 1)
		hd_read(&data);
	else if (! hd_strcmp(av[1], "-C"))
	{
		data.canon = 1;
		data.argnum = 2;
		if (ac == 2)
			hd_read(&data);
	}
	while (data.argnum < data.ac)
	{
		data.fd = hd_open(av[data.argnum]);
		if (data.fd == -1 || hd_read(&data))
			hd_err(ERR_CANT_OPEN, av[0], av[data.argnum]);
		close(data.fd);
		data.argnum++;
	}
	if (data.buf)
		end_file(&data);
	return (0);
}

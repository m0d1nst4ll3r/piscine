/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:41:50 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/01 23:16:46 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	hd_print(char *bytes, int pos, int canon)
{
	if (pos > 0 && hd_strlen(bytes + pos) > 15
		&& hd_strncmp(bytes + pos, ))
	hd_print_mem()
}

int	hd_read(char *file, int *pos, char **bytes, int canon)
{
	int		fd;
	int		size;
	int		i;
	char	buf[BUFSIZE];

	fd = hd_open(file);
	if (fd == -1)
		return (1);
	size = read(fd, buf, BUFSIZE);
	while (size)
	{
		i = -1;
		while (++i < size)
			*bytes = hd_realloc(*bytes, buf[i]);
		while (hd_strlen(*bytes, pos, canon) >= 16)
		{
			hd_print(*bytes, pos, canon)
			pos += 16;
		}
		size = read(fd, buf, BUFSIZE);
	}
	return (0);
}

int	hexdump(char *file, int ac, int argnum, int canon)
{
	int		pos;
	char	*bytes;

	pos = 0;
	bytes = 0;
	if (hd_read(file))
		hd_err(ERR_CANT_OPEN);
	hd_read(file, &pos, &bytes, canon);
	if (argnum < ac)
		hd_print(bytes, pos, canon);
}

int	main(int ac, char **av)
{
	int		i;
	int		canon;

	canon = 0;
	i = 1;
	if (ac == 1)
		hexdump(0, 0, 0, canon);
	if (hd_strmcp(av[1],"-C"))
	{
		canon = 1;
		i = 2;
		if (ac == 2)
			hexdump(0, 0, 0, canon);
	}
	while (i < ac)
	{
		if (hexdump(av[i], ac, argnum, canon))
			hd_err(ERR_CANT_OPEN, av[0], av[i]);
		i++;
	}
	return (0);
}

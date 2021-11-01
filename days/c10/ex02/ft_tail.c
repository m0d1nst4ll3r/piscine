/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:31:29 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/27 21:24:17 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static void	display(char *file, t_byte *list, int ac, int argnum)
{
	if (ac > 4)
	{
		if (argnum > 3)
			ft_putstr("\n", 1);
		ft_putstr("==> ", 1);
		ft_putstr(file, 1);
		ft_putstr(" <==\n", 1);
	}
	while (list)
	{
		write(1, &(list->byte), 1);
		list = list->next;
	}
}

static int	read_file(char *file, int limit, int ac, int argnum)
{
	int		fd;
	int		size;
	int		i;
	char	buf[BUFSIZE];
	t_byte	*list;

	fd = ft_open(file);
	if (fd == -1)
		return (1);
	size = read(fd, buf, BUFSIZE);
	list = 0;
	while (size)
	{
		i = -1;
		while (++i < size)
		{
			insert_back(&list, buf[i]);
			if (list_size(list) > limit)
				remove_front(&list);
		}
		size = read(fd, buf, BUFSIZE);
	}
	display(file, list, ac, argnum);
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	limit;

	if (ac < 2)
		return (0);
	if (ft_strcmp(av[1], "-c"))
		return (0);
	if (ac < 3)
		return (ft_err(ERR_NO_ARG, av[0], 0));
	limit = ft_atoi(av[2]);
	if (limit == -1)
		return (ft_err(ERR_INVALID_ARG, av[0], av[2]));
	if (ac == 3)
		read_file(0, limit, ac, 0);
	i = 3;
	while (i < ac)
	{
		if (read_file(av[i], limit, ac, i))
			ft_err(ERR_CANT_OPEN, av[0], av[i]);
		i++;
	}
	return (0);
}

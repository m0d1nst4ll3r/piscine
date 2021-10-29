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

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *str, int )
{
	while (*str)
		write(1, str++, 1);
}

int		ft_puterr(char *name, char *file, int err)
{
	ft_putstr(name);
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(err));
	ft_putstr("\n");
	return (err);
}

//	Returns file descriptor after opening
//	or STDIN_FILENO if name points to a NULL adress
//
//	Will also check if file is a directory
//	and return -1 if it is.
//	errno will be manually updated.
int	ft_open(char *name)
{
	int	fd;

	if (name)
	{
		fd = open(name, O_RDONLY | O_DIRECTORY);
		if (fd == -1)
			fd = open(name, O_RDONLY);
		else
		{
			close(fd);
			errno = EISDIR;
			return (-1);
		}
	}
	else
		return (STDIN_FILENO);
	return (fd);
}

int	read_file(char *name)
{
	int		fd;
	int		size;
	char	buf[4096];
	char	*buft;

	if ((fd = ft_open(name) == -1))
		return (1);
	if (fd == -1)
		return (errno);
	size = read(fd, buf, 4096);
	while (size)
	{
		buft = buf;
		while (size--)
			write(1, buft++, 1);
		size = read(fd, buf, 4096);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (read_file(0));
	i = 1;
	while (i < ac)
	{
		if (read_file(av[i]))
			ft_puterr(av[0], av[i], errno);
		i++;
	}
	return (0);
}

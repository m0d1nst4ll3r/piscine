/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:31:29 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/31 21:14:11 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str, int size)
{
	while (size--)
		write(1, str++, 1);
}

int		ft_open(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		return (open (name, O_RDONLY));
	else
	{
		close(fd);
		return (-1);
	}
}

int	main(int ac, char **av)
{
	int		fd;
	int		size;
	char	buf[256];

	if (ac < 2)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = ft_open(av[1]);
		if (fd == -1)
			write(2, "Cannot read file.\n", 18);
		else
		{
			size = read(fd, buf, 256);
			while (size)
			{
				ft_putstr(buf, size);
				size = read(fd, buf, 256);
			}
		}
	}
	return (0);
}

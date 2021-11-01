/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:41:29 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/01 23:16:56 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*hd_realloc(char *old, char byte)
{
	char	*new;
	int		i;

	i = 0;
	if (! old)
		new = malloc(sizeof(*new) * 2);
	else
	{
		while (old[i])
			i++;
		new = malloc(sizeof(*new) * (i + 2));
		i = -1;
		while (old[++i])
			new[i] = old[i];
		free(old);
	}
	new[i] = byte;
	new[i + 1] = 0;
	return (new);
}

int	hd_open(char *file)
{
	int	fd;

	if (! file)
		return (STDIN_FILENO);
	fd = open(file, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		errno = EISDIR;
		return (-1);
	}
	fd = open(file, O_RDONLY);
	return (fd);
}

int	hd_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i)
}

int	hd_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	hd_strcmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

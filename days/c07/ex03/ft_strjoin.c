/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:05:40 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/22 13:40:30 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	destlen;
	int	srclen;
	int	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = destlen;
	while (i < (srclen + destlen))
	{
		dest[i] = src[i - destlen];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	ft_strjoin_fill(int size, char **strs, char *sep, char *join)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(join, strs[i]);
		if (i < size - 1)
			ft_strcat(join, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		totlen;
	char	*join;

	if (size <= 0)
		return (malloc(sizeof(char)));
	i = 0;
	totlen = 0;
	while (i < size)
	{
		totlen += ft_strlen(strs[i]);
		i++;
	}
	totlen += ft_strlen(sep) * size - 1;
	join = malloc(sizeof(*join) * (totlen + 1));
	if (! join)
		return (NULL);
	ft_strjoin_fill(size, strs, sep, join);
	return (join);
}

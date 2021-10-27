/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:05:40 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/27 18:27:37 by rpohlen          ###   ########.fr       */
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
	char	*error;

	if (size <= 0)
	{
		error = malloc(sizeof(char));
		if (error == NULL)
			return (NULL);
		*error = 0;
		return (error);
	}
	i = -1;
	totlen = 0;
	while (++i < size)
		totlen += ft_strlen(strs[i]);
	totlen += ft_strlen(sep) * (size - 1);
	join = malloc(sizeof(*join) * (totlen + 1));
	if (join == NULL)
		return (NULL);
	*join = 0;
	ft_strjoin_fill(size, strs, sep, join);
	return (join);
}

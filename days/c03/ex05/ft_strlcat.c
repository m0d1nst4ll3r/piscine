/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:01:25 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/17 15:51:49 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	while (i + destlen < size)
	{
		if (i + destlen == size - 1)
			dest[i + destlen] = 0;
		else
			dest[i + destlen] = src[i];
		if (! dest[i])
			break ;
		i++;
	}
	if (size < destlen)
		return (size + srclen);
	return (destlen + srclen);
}

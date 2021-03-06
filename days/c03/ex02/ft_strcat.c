/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:53:56 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/17 12:54:53 by rpohlen          ###   ########.fr       */
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

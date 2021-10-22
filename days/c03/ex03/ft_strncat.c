/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:53:26 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/17 13:24:11 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strnlen(char *str, int nb)
{
	int	i;

	i = 0;
	while (str[i] && i < nb)
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	destlen;
	int	srclen;
	int	i;

	destlen = ft_strlen(dest);
	srclen = ft_strnlen(src, nb);
	i = destlen;
	while (i < (srclen + destlen))
	{
		dest[i] = src[i - destlen];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

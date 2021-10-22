/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:25:01 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/17 13:59:32 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *tofind)
{
	int	hslen;
	int	ndlen;
	int	i;
	int	j;

	hslen = ft_strlen(str);
	ndlen = ft_strlen(tofind);
	i = 0;
	while (hslen - i >= ndlen)
	{
		j = 0;
		while (str[i + j] == tofind[j] && j < ndlen)
			j++;
		if (j == ndlen)
			return (str + i);
		i++;
	}
	return (NULL);
}

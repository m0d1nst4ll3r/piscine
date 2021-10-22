/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:47:47 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/18 15:50:02 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				end;

	i = 0;
	end = 0;
	while (i < n)
	{
		if (src[i] == 0)
			end = 1;
		if (end)
			dest[i] = 0;
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}

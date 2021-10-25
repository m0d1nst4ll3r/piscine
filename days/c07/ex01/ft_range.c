/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:21:32 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/25 14:10:52 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*itab;
	int	i;

	if (min >= max)
		return (NULL);
	itab = malloc(sizeof(*itab) * (max - min));
	if (! itab)
		return (NULL);
	i = 0;
	while (i < (max - min))
	{
		itab[i] = min + i;
		i++;
	}
	return (itab);
}

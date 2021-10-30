/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:33:21 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/29 12:42:32 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*new;
	int	i;

	if (! tab)
		return (NULL);
	new = malloc(sizeof(*new) * length);
	if (new == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		new[i] = (*f)(tab[i]);
	return (new);
}

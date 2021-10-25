/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:26:35 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/25 19:49:00 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//	Allocates an array of [ac] structures
//	Fills that array one by one by assigning to:
//		array.size		the length of the string
//		array.str		the address of the string
//		array.copy		the address of a copy of the string
//	The last element of the array will have a NULL adress as its [str]
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;
	int					j;

	tab = malloc(sizeof(*tab) * (ac + 1));
	if (! tab)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		tab[i].copy = malloc(sizeof(*(tab->str)) * (j + 1));
		if (! tab[i].copy)
			return (NULL);
		j = -1;
		while (av[i][++j])
			tab[i].copy[j] = av[i][j];
		tab[i].size = j;
		tab[i].str = av[i];
	}
	tab[i].str = 0;
	return (tab);
}

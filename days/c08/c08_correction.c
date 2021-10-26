/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c08_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:36:46 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/25 20:19:23 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ex04/ft_stock_str.h"

t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(struct s_stock_str *par);

int	main(int ac, char **av)
{
	t_stock_str	*test;
	test = ft_strs_to_tab(ac, av);
	ft_show_tab(test);
}

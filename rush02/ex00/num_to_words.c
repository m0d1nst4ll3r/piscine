/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:30:00 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 20:05:53 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num_to_words.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ntw_check_dic(DEFAULT_DIC))
	{
		ft_puterr(EBADDIC);
		return (1);
	}
	else
		ft_putstr("Dictionary is good\n");
	return (0);
}

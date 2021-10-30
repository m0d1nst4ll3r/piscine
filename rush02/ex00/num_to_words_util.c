/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:04:22 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 21:14:21 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num_to_words.h"

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}



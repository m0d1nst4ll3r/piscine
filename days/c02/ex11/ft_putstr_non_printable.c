/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:43:21 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/20 16:23:32 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Writes char value between 0 and 15 as its hex character
void	ft_puthex(char h)
{
	if (h < 10)
		h = h + '0';
	else
		h = h - 10 + 'a';
	write(1, &h, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 31 && str[i] != 127)
			write(1, str + i, 1);
		else
		{
			write(1, "\\", 1);
			ft_puthex((unsigned char)str[i] / 16);
			ft_puthex((unsigned char)str[i] % 16);
		}
		i++;
	}
}

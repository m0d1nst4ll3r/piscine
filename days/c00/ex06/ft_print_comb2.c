/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:03:16 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/15 13:04:21 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Converts a single-digit int to its char value to use in displaying
char	itoc(int n)
{
	return (n + 48);
}

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = 0;
		while (b <= 99)
		{
			if (a < b)
			{
				ft_print_char(itoc(a / 10));
				ft_print_char(itoc(a - a / 10 * 10));
				ft_print_char(' ');
				ft_print_char(itoc(b / 10));
				ft_print_char(itoc(b - b / 10 * 10));
				if (a != 98 || b != 99)
					write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}

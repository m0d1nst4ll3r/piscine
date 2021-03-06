/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:04:33 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/15 13:04:35 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a[3];

	a[0] = '0';
	while (a[0] <= '9')
	{
		a[1] = '0';
		while (a[1] <= '9')
		{
			a[2] = '0';
			while (a[2] <= '9')
			{
				if (a[2] > a[1] && a[1] > a[0])
				{
					write(1, &a[0], 1);
					write(1, &a[1], 1);
					write(1, &a[2], 1);
					if (a[0] != '7' || a[1] != '8' || a[2] != '9')
						write(1, ", ", 2);
				}
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
}

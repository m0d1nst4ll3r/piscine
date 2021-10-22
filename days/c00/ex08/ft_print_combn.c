/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <raphaelpohlen@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:12:55 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/15 13:14:24 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Initializes array at '0'
void	ft_init(char *t, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		t[i] = '0';
		i++;
	}
}

// Writes all the digits in the array followed by ", "
// Will not write ", " for last string
void	ft_writedigits(char *d, int size)
{
	int		i;
	char	verif;

	i = 0;
	verif = '9';
	while (i < size)
	{
		ft_putchar(d[i]);
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (d[i] != verif)
		{
			break ;
		}
		i--;
		verif--;
	}
	if (i != -1)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	digits[9];
	int		x;
	int		y;

	ft_init(digits, n);
	while (digits[0] <= '9')
	{
		y = 0;
		while (y < n - 1)
		{
			if (digits[y] >= digits[y + 1])
				break ;
			y++;
		}
		if (y == n - 1 || n == 1)
			ft_writedigits(digits, n);
		x = n - 1;
		while (x != 0 && digits[x] == '9')
		{
			digits[x] = '0';
			x--;
		}
		digits[x]++;
	}
}

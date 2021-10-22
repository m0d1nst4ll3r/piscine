/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:03:36 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/15 13:04:15 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Writes char on screen
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Returns exponential of ten, starting from 0
int	ft_expoften(int e)
{
	int	r;

	r = 10;
	if (e == 0)
		r = 1;
	while (e > 1)
	{
		r = r * 10;
		e--;
	}
	return (r);
}

// Get number of digits of int
int	ft_getsize(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

// Displays nb
void	ft_putnbr(int nb)
{
	int	digit;
	int	neg;
	int	size;

	size = ft_getsize(nb);
	neg = 1;
	if (nb < 0)
	{
		neg = -1;
		ft_putchar('-');
	}
	while (size > 0)
	{
		digit = nb / ft_expoften(size - 1);
		ft_putchar(neg * digit + 48);
		nb = nb - digit * ft_expoften(size - 1);
		size--;
	}
}

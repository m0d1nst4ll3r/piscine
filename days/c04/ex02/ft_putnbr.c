/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:57:17 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/17 16:24:29 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_expoften(int e)
{
	int	i;
	int	n;

	if (e <= 0)
		return (1);
	i = 1;
	n = 10;
	while (i < e)
	{
		n = n * 10;
		i++;
	}
	return (n);
}

int	ft_getdigits(int n)
{
	int	i;

	if (! n)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	int	i;
	int	digit;
	int	neg;

	neg = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		neg = -1;
	}
	i = ft_getdigits(nb);
	while (i)
	{
		digit = nb / ft_expoften(i - 1);
		ft_putchar(digit * neg + '0');
		nb = nb - digit * ft_expoften(i - 1);
		i--;
	}
}

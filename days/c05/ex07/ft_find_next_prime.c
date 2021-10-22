/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:18:18 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/22 13:18:21 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long int	i;
	long int	n;

	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	i = 2;
	n = (long int)nb;
	while (n % i && (i * i) < n)
		i++;
	if (n % i)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (! ft_is_prime(nb))
		nb++;
	return (nb);
}

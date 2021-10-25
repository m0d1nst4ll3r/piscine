/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:16:25 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/25 15:39:47 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_recursive(int start, int end, int nb)
{
	long int	mid;
	long int	n;

	mid = start + ((end - start) / 2);
	n = (long int)nb;
	if (((mid * mid) < n) && (((mid + 1) * (mid + 1)) > n))
		return (0);
	else if ((mid * mid) > n)
		return (ft_sqrt_recursive(start, mid, nb));
	else if ((mid * mid) < n)
		return (ft_sqrt_recursive(mid, end, nb));
	else
		return (mid);
}

int	ft_sqrt(int nb)
{
	if (nb < 1)
		return (0);
	else if (nb == 1)
		return (1);
	return (ft_sqrt_recursive(0, nb, nb));
}

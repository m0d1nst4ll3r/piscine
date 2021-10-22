/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:54:07 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/22 14:39:08 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_getlen(int nbr, int base)
{
	int	len;
	int	neg;

	if (nbr == 0)
		return (1);
	neg = 0;
	if (nbr < 0)
		neg = 1;
	len = 0;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len + 1);
}

void	ft_itoa_base(char *fill, int n, char *base, int baselen, int i)
{
	if (n < baselen)
		fill[i] = base[n];
	else
	{
		ft_itoa_base(fill, n / baselen, base, baselen, i - 1);
		ft_itoa_base(fill, n % baselen, base, baselen, i - 1);
	}
}

// Say we have 267

// We want to write 2 in [0] 6 in [1] 7 in [2]

// In a recursive func, we will call with	267				at 0 of depth
// Then it will call itself with			26 and 7		at 1 of depth
// Then call itself with					2 and 6			at 2 of depth

// In a recursive func, we will call with	2673			at 0 of depth
// Then it will call itself with			267 and 3		at 1 of depth
// Then call itself with					2 and 6			at 2 of depth

// We notice that the units are at 1 depth ... unless they're at 0 because we have a unit right away
// The tenths 

// This is tough.

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		baselen;
	int		num;
	char	*cnvrt;

	baselen = ft_check_base(base_to);
	if (ft_check_base(base_from) <= 1 || len <= 1)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	cnvrt = malloc (sizeof(*cnvrt) * (ft_getlen(num, baselen) + 1));
	if (cnvrt == 0)
		return (0);
	ft_itoa_base(cnvrt, num, base, baselen, baselen - 1);
	return (cnvrt);
}

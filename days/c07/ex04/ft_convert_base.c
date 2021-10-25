/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:54:07 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/25 16:25:06 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_base(char *base);
int	ft_atoi_base(char *str, char *base);

//	Returns number of digits of an int [nbr],
//		if it were written in base [base]
//	Takes into account negatives and adds 1 to the length
//		for the minus character
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
	return (len + neg);
}

//	Fills string [fill] with the int [n] converted in base [base]
//		of length [baselen]
//	Makes sure to add a '-' for negative numbers and 0 to end the string
void	ft_itoa_base(char *fill, int n, char *base, int baselen)
{
	int	i;
	int	neg;

	i = ft_getlen(n, baselen);
	fill[i] = 0;
	neg = 1;
	if (n < 0)
		neg = -1;
	while (i >= 0)
	{
		fill[i - 1] = base[(n * neg) % baselen];
		n /= baselen;
		i--;
	}
	if (neg == -1)
		fill[0] = '-';
}

//	Converts the string into an int, first, by using atoi_base
//	Allocates enough memory to fit the number in base [base_to],
//		its negative sign, and a terminating 0
//	Reconverts the string into the allocated new string by using itoa_base
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		baselen;
	int		num;
	char	*cnvrt;

	baselen = ft_check_base(base_to);
	if (ft_check_base(base_from) <= 1 || baselen <= 1)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	cnvrt = malloc (sizeof(*cnvrt) * (ft_getlen(num, baselen) + 1));
	if (cnvrt == 0)
		return (0);
	ft_itoa_base(cnvrt, num, base_to, baselen);
	return (cnvrt);
}

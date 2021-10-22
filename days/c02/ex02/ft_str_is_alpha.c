/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:47:54 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/16 12:55:49 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	islower;
	int	isupper;

	i = 0;
	while (str[i])
	{
		islower = str[i] >= 'a' && str[i] <= 'z';
		isupper = str[i] >= 'A' && str[i] <= 'Z';
		if (! (islower || isupper))
			return (0);
		i++;
	}
	return (1);
}

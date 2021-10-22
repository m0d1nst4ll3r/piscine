/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:16:02 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/16 13:29:27 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	inword;

	i = 0;
	inword = 0;
	while (str[i])
	{
		if (ft_isnum(str[i]) || ft_islower(str[i]) || ft_isupper (str[i]))
		{
			if (! inword && ft_islower(str[i]))
				str[i] = str[i] + ('A' - 'a');
			else if (inword && ft_isupper(str[i]))
				str[i] = str[i] - ('A' - 'a');
			inword = 1;
		}
		else
			inword = 0;
		i++;
	}
	return (str);
}

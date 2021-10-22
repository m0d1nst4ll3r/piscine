/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:56:31 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/17 18:17:24 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

// -----------------------------------------------------------------------
//	ft_expoften :
//
//	Returns 10 ^ e.
//	Negative values of e will default to 0.
//
//	example :
//	1000	<-	ft_expoften(3)
//
//	- e:	exponential of ten
// -----------------------------------------------------------------------
int	ft_expoften(int e)
{
	int	result;
	int	i;

	if (e <= 0)
		return (1);
	result = 10;
	i = 1;
	while (i < e)
	{
		result = result * 10;
		i++;
	}
	return (result);
}

// -----------------------------------------------------------------------
//	ft_strnumlen :
//
//	Counts the amount of digits present consecutively in a string.
//	Only counts digits present at the very start of the string.
//	If the first character of the string is not a number,
//	the function will return 0.
//
//	example :
//	5	<-	ft_strnumlen("07685abcdef\n")
//
//	- str:	string to count numbers in
// -----------------------------------------------------------------------
int	ft_strnumlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

// -----------------------------------------------------------------------
//	ft_atoi :
//
//	Converts a string into an int
//	Will return 0 if any non-numeric bytes precede the number
//	As such, spaces, minus, and plus are not handled
//
//	example :
//	1234	<-	ft_atoi("1234eeee")
//	0		<-			"+1234"
//
//	- str:	string to convert
// -----------------------------------------------------------------------
int	ft_atoi(char *str)
{
	int	i;
	int	len;
	int	n;

	len = ft_strnumlen(str);
	i = len - 1;
	n = 0;
	while (i >= 0)
	{
		n = n + ft_expoften(len - (i + 1)) * (str[i] - '0');
		i--;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	if (argc >= 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}

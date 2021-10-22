/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:25:04 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/22 12:59:06 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_tenq_print(char *queens)
{
	int	i;
	int	c;

	i = -1;
	while (++i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	ft_tenq_check(char *queens, int col)
{
	int		i;
	char	line;
	char	diagtop;
	char	diagbot;

	i = col - 1;
	while (i > -1)
	{
		line = (queens[col] == queens[i]);
		diagtop = (queens[col] == queens[i] + (col - i));
		diagbot = (queens[col] == queens[i] - (col - i));
		if (line || diagtop || diagbot)
			return (0);
		i--;
	}
	return (1);
}

void	ft_tenq_rec(char *queens, int *res, int col)
{
	if (col == 10)
	{
		ft_tenq_print(queens);
		*res = *res + 1;
		return ;
	}
	queens[col] = 0;
	while (queens[col] < 10)
	{
		if (ft_tenq_check(queens, col))
			ft_tenq_rec(queens, res, col + 1);
		queens[col]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	queens[10];
	int		res;

	res = 0;
	ft_tenq_rec(queens, &res, 0);
	return (res);
}

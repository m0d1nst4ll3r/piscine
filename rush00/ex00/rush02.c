/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:56:24 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/22 14:48:20 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// -----------------------------------------------------------------------
//  write_rectangle :
//
//  Writes one of 9 possible characters depending on
//  position i, j in the rectangle of size x, y.
//
//  The 9 possible positions, in the order as
//  they appear in the function, are:
//
//  TOP LEFT, TOP RIGHT, TOP
//  BOTTOM LEFT, BOTTOM RIGHT, BOTTOM
//  LEFT, RIGHT, MIDDLE
//
//  A A B
//  C C B
//  B B  
//
//  - x:    total number of lines of the rectangle
//  - y:    total number of columns of the rectangle
//  - i:    current line
//  - j:    current column
// -----------------------------------------------------------------------
void	write_rectangle(int x, int y, int i, int j)
{
	if (i == 1 && j == 1)
		ft_putchar('A');
	else if (i == 1 && j == y)
		ft_putchar('A');
	else if (i == 1)
		ft_putchar('B');
	else if (i == x && j == 1)
		ft_putchar('C');
	else if (i == x && j == y)
		ft_putchar('C');
	else if (i == x)
		ft_putchar('B');
	else if (j == 1)
		ft_putchar('B');
	else if (j == y)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

// -----------------------------------------------------------------------
//  rush :
//
//  Draws a rectangle of x columns and y lines
//  With characters "o|- "
//
//  example:
//  rush(2,3)
//
//  AA
//  BB
//  CC
//
//  - x:    number of columns to draw
//  - y:    number of lines to draw
// -----------------------------------------------------------------------
void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0)
		return ;
	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			write_rectangle(y, x, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

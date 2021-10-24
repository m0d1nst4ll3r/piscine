/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:44 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/24 20:16:30 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----------------------------------------------------------------------
**
**		backwards_check
**	
**	Checks for duplicates of a value, backwards,
**	on the same line and column.
**
**		returns
**
**	- 1		if no duplicate was found
**	- 0		otherwise
**
**		params
**
**	- map:		two dimensional array on which to check for duplicates
**	- x:		x coordinate of the value we are checking
**	- y:		y coordinate of the value we are checking
**
** -------------------------------------------------------------------- */
int	backwards_check(char **map, int x, int y)
{
	int	i;

	i = y - 1;
	while (i >= 0)
	{
		if (map[x][y] == map[x][i])
			return (0);
		i--;
	}
	i = x - 1;
	while (i >= 0)
	{
		if (map[x][y] == map[i][y])
			return (0);
		i--;
	}
	return (1);
}

/* -----------------------------------------------------------------------
**
**		line_left_check
**	
**	Calculates how many boxes we will see on a line,
**	when looking at it from the left side.
**	Then, checks that value against the value we were
**	given in our input.
**
**		returns
**
**	- 1		if the values match
**	- 0		otherwise
**
**		params
**
**	- map:		two dimensional array where the line is located
**	- input:	value against which to check
**	- size:		size of our two dimension array
**	- num:		number of the line to check
**
** -------------------------------------------------------------------- */
int	line_left_check(char **map, int input, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = 1;
	highest = map[num][0];
	while (i <= size - 1)
	{
		if (highest < map[num][i])
		{
			highest = map[num][i];
			score++;
		}
		i++;
	}
	if (score != input)
		return (0);
	return (1);
}

/* -----------------------------------------------------------------------
**
**		line_right_check
**	
**	Calculates how many boxes we will see on a line,
**	when looking at it from the right side.
**	Then, checks that value against the value we were
**	given in our input.
**
**		returns
**
**	- 1		if the values match
**	- 0		otherwise
**
**		params
**
**	- map:		two dimensional array where the line is located
**	- input:	value against which to check
**	- size:		size of our two dimension array
**	- num:		number of the line to check
**
** -------------------------------------------------------------------- */
int	line_right_check(char **map, int input, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = size - 2;
	highest = map[num][size - 1];
	while (i >= 0)
	{
		if (highest < map[num][i])
		{
			highest = map[num][i];
			score++;
		}
		i--;
	}
	if (score != input)
		return (0);
	return (1);
}

/* -----------------------------------------------------------------------
**
**		col_top_check
**	
**	Calculates how many boxes we will see on a column,
**	when looking at it from the top.
**	Then, checks that value against the value we were
**	given in our input.
**
**		returns
**
**	- 1		if the values match
**	- 0		otherwise
**
**		params
**
**	- map:		two dimensional array where the column is located
**	- input:	value against which to check
**	- size:		size of our two dimension array
**	- num:		number of the column to check
**
** -------------------------------------------------------------------- */
int	col_top_check(char **map, int input, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = 1;
	highest = map[0][num];
	while (i <= size - 1)
	{
		if (highest < map[i][num])
		{
			highest = map[i][num];
			score++;
		}
		i++;
	}
	if (score != input)
		return (0);
	return (1);
}

/* -----------------------------------------------------------------------
**
**		col_bot_check
**	
**	Calculates how many boxes we will see on a column,
**	when looking at it from the bottom.
**	Then, checks that value against the value we were
**	given in our input.
**
**		returns
**
**	- 1		if the values match
**	- 0		otherwise
**
**		params
**
**	- map:		two dimensional array where the column is located
**	- input:	value against which to check
**	- size:		size of our two dimension array
**	- num:		number of the column to check
**
** -------------------------------------------------------------------- */
int	col_bot_check(char **map, int input, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = size - 2;
	highest = map[size - 1][num];
	while (i >= 0)
	{
		if (highest < map[i][num])
		{
			highest = map[i][num];
			score++;
		}
		i--;
	}
	if (score != input)
		return (0);
	return (1);
}

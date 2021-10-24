/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:32 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/24 20:34:15 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box_puzzle.h"

/* -----------------------------------------------------------------------
**
**		mega_check
**
**	Combines all the following checks to make sure the rules
**	of the game are followed :
**
**		- No duplicates on the same line or column (backwards check)
**		- Each line must respect the values we were given (line checks)
**		- Each column must respect the values we were given (column checks)
**
**	Only checks for lines and columns when needed
**		(not before we have completed a line or column)
**
**		returns
**
**	- 1 		if all the checks were successful
**	- 0			otherwise
**
**		params
**
**	- input:	2d array of ints that contains our input
**	- map:		2d array of chars which symbolizes our playground
**	- size:		size of the two former arrays
**	- xy:		xy position of the value we have to check for
**
** -------------------------------------------------------------------- */
int	mega_check(int **input, char **map, int size, int *xy)
{
	char	bwcheck;
	char	line_r;
	char	line_l;
	char	col_t;
	char	col_b;

	bwcheck = backwards_check(map, xy[0], xy[1]);
	line_l = 1;
	line_r = 1;
	col_t = 1;
	col_b = 1;
	if (bwcheck && xy[0] == size - 1)
	{
		col_t = col_top_check(map, input[0][xy[1]], size, xy[1]);
		col_b = col_bot_check(map, input[1][xy[1]], size, xy[1]);
	}
	if (bwcheck && xy[1] == size - 1)
	{
		line_l = line_left_check(map, input[2][xy[0]], size, xy[0]);
		line_r = line_right_check(map, input[3][xy[0]], size, xy[0]);
	}
	return (bwcheck && line_r && line_l && col_t && col_b);
}

/* -----------------------------------------------------------------------
**
**		box_recursive
**
**	Core recursive function of the program.
**
**	Starts at position [0, 0] as called in box_puzzle.
**
**	Will fill each position from start to end with values
**	between 1 and SIZE, while making sure to follow the rules
**	of the game.
**
**	If a value is not valid according to the rules, the function
**	will naturally increment the value until it goes past SIZE,
**	at which point it will naturally exit and go back to the
**	previous box.
**
**	If the function exits at position [0, 0], it will return 0
**	to box_puzzle.
**
**	If the function reaches position [SIZE - 1, SIZE - 1],
**	meaning the end of the map, and all the rules were followed so far,
**	it will	return 1 to box_puzzle.
**
**		returns
**
**	- 1 		if a solution was found
**	- 0			otherwise
**
**		params
**
**	- input:	2d array of ints that contains our input
**	- map:		2d array of chars which symbolizes our playground
**	- size:		size of the two former arrays
**	- xy:		current xy position we are filling
**					starts at [0, 0]
**					ends at [size - 1, size - 1]
**
** -------------------------------------------------------------------- */
int	box_recursive(int **input, char **map, int size, int *xy)
{
	int		next[2];

	map[xy[0]][xy[1]] = 1;
	while (map[xy[0]][xy[1]] <= size)
	{
		if (mega_check(input, map, size, xy))
		{
			if (xy[1] == size - 1 && xy[0] == size - 1)
				return (1);
			next[0] = xy[0];
			next[1] = xy[1] + 1;
			if (xy[1] == size - 1)
			{
				next[1] = 0;
				next[0] = xy[0] + 1;
			}
			if (box_recursive(input, map, size, next))
				return (1);
		}
		map[xy[0]][xy[1]]++;
	}
	return (0);
}

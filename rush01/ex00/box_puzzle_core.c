/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:32 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/23 18:10:40 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box_puzzle.h"

int	mega_check(int **input, char **map, int size, int *xy)     // xy[0] is X     xy[1] is Y
{
	char	bwcheck; // "booleans" used to check for rules
	char	line_r;
	char	line_l;
	char	col_t;
	char	col_b;

	bwcheck = backwards_check(map, xy[0], xy[1]); // backwards check
	line_l = 1;
	line_r = 1;
	col_t = 1;
	col_b = 1;
	if (xy[1] == size - 1) // line check
	{
		line_l = line_left_check(input, map, size, xy[0]); // left
		line_r = line_right_check(input, map, size, xy[0]); // right
	}
	if (xy[0] == size - 1) // column check
	{
		col_t = col_top_check(input, map, size, xy[1]); // top
		col_b = col_bot_check(input, map, size, xy[1]); // bottom
	}
	return (bwcheck && line_r && line_l && col_t && col_b); // return combination of checks
}



int	box_recursive(int **input, char **map, int size, int *xy)     // xy[0] is X     xy[1] is Y
{
	int		next[2]; // values we'll send for next call

	map[xy[0]][xy[1]] = 1; // start at 1
	while (map[xy[0]][xy[1]] <= size) // end at size
	{
		if (mega_check(input, map, size, xy)) // check all the rules are respected
		{
			if (xy[1] == size - 1 && xy[0] == size - 1) // if we're at the end of the map (size - 1 for X and Y)
				return (1); // return 1 and start the cascade
			next[0] = xy[0];
			next[1] = xy[1] + 1;
			if (xy[1] == size - 1) // set next X and Y depending on whether we're at the end of a line
			{
				next[1] = 0;
				next[0] = xy[0] + 1;
			}
			if (box_recursive(input, map, size, next)) // RECURSION: call next function with next position in map
				return (1); // cascade of return 1's
		}
		map[xy[0]][xy[1]]++; // try higher box
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:32 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/23 15:23:07 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box_puzzle.h"

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
	if (xy[1] == size - 1)
	{
		line_r = line_right_check(input, map, size, xy[0]);
		line_l = line_left_check(input, map, size, xy[0]);
	}
	if (xy[0] == size - 1)
	{
		col_t = col_top_check(input, map, size, xy[1]);
		col_b = col_bot_check(input, map, size, xy[1]);
	}
	return (bwcheck && line_r && line_l && col_t && col_b);
}

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

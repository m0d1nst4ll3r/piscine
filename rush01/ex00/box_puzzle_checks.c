/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:44 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/23 18:10:37 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	backwards_check(char **map, int x, int y)
{
	int	i;

	i = y - 1;
	while (i >= 0) // line (right to left)
	{
		if (map[x][y] == map[x][i])
			return (0);
		i--;
	}
	i = x - 1;
	while (i >= 0) // column (bottom to top)
	{
		if (map[x][y] == map[i][y])
			return (0);
		i--;
	}
	return (1);
}

// order in which the input is written as an argument : "top bottom left right"
// input[0]	->	top
// input[1]	->	bottom
// input[2]	->	left
// input[3]	->	right
int	line_left_check(int **input, char **map, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = 1;
	highest = map[num][0]; // map [LINE] [0], meaning, the leftmost box
	while (i <= size - 1) // from 1 to size - 1
	{
		if (highest < map[num][i])
		{
			highest = map[num][i];
			score++; // increment score if we can see another box behind the highest we've come across so far
		}
		i++;
	}
	if (score != input[2][num]) // check against our input
		return (0);
	return (1);
}

int	line_right_check(int **input, char **map, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = size - 2;
	highest = map[num][size - 1]; // rightmost box
	while (i >= 0)
	{
		if (highest < map[num][i])
		{
			highest = map[num][i];
			score++;
		}
		i--;
	}
	if (score != input[3][num])
		return (0);
	return (1);
}

int	col_top_check(int **input, char **map, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = 1;
	highest = map[0][num]; // top box
	while (i <= size - 1)
	{
		if (highest < map[i][num])
		{
			highest = map[i][num];
			score++;
		}
		i++;
	}
	if (score != input[0][num])
		return (0);
	return (1);
}

int	col_bot_check(int **input, char **map, int size, int num)
{
	int	i;
	int	score;
	int	highest;

	score = 1;
	i = size - 2;
	highest = map[size - 1][num]; // bottom box
	while (i >= 0)
	{
		if (highest < map[i][num])
		{
			highest = map[i][num];
			score++;
		}
		i--;
	}
	if (score != input[1][num])
		return (0);
	return (1);
}

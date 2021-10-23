/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:44 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/23 13:59:46 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	line_left_check(int **input, char **map, int size, int num)
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
	if (score != input[2][num])
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
	if (score != input[1][num])
		return (0);
	return (1);
}

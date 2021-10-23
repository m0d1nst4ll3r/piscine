/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:15 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/23 14:01:55 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box_puzzle.h"

void	print_map(char **map, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i <= size - 1)
	{
		j = 0;
		while (j <= size - 1)
		{
			c = map[i][j] + '0';
			write(1, &c, 1);
			if (j < size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	check_input(char *str)
{
	int	i;
	int	size;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && ! (str[i] >= '1' && str[i] <= '9'))
			return (0);
		else if (i % 2 == 1 && str[i] != ' ')
			return (0);
		i++;
	}
	if (i == 0 || i >= 9 * 8 || (i + 1) % 8 != 0)
		return (0);
	size = (i + 1) / 8;
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && ! (str[i] >= '1' && str[i] <= size + '0'))
			return (0);
		i++;
	}
	return (size);
}

int	**format_input(char *str, int size)
{
	int	**input;
	int	i;
	int	j;

	input = malloc(sizeof(*input) * 4);
	if (input == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		input[i] = malloc(sizeof(*input[i]) * size);
		if (input[i] == 0)
			return (0);
		j = 0;
		while (j < size)
		{
			input[i][j] = str[i * size * 2 + j * 2] - '0';
			j++;
		}
		i++;
	}
	return (input);
}

char	**create_map(int size)
{
	int		i;
	char	**map;

	map = malloc(sizeof(*map) * size);
	if (map == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		map[i] = malloc(sizeof(*map[i]) * size);
		if (map[i] == 0)
			return (0);
		i++;
	}
	return (map);
}

int	box_puzzle(int argc, char **argv)
{
	int		size;
	int		**input;
	char	**map;
	int		xy[2];

	if (argc != 2)
		return (0);
	size = check_input(argv[1]);
	if (size < 1)
		return (0);
	input = format_input(argv[1], size);
	if (input == 0)
		return (0);
	map = create_map(size);
	if (map == 0)
		return (0);
	xy[0] = 0;
	xy[1] = 0;
	if (box_recursive(input, map, size, xy))
		print_map(map, size);
	else
		return (0);
	return (1);
}

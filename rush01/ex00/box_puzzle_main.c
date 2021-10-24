/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:59:15 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/24 20:16:11 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box_puzzle.h"

/* -----------------------------------------------------------------------
**
**		print_map
**
**	Display every value of a two-dimensional array.
**	Values are separated by spaces.
**	Lines are separated by newlines.
**
**		params
**
**	- map:		two dimensional array to display
**	- size:		size of the array
**
** -------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------
**
**		check_input
**
**	Checks for the validity of the string of characters
**	we received as our input.
**
**		The rules are as follows :
**	- The string must be "digit, space, digit, space"
**	- The string must be of the correct length
**		not less than an array of 1x1 would require
**		not more than an array of 9x9 would require
**		not of any size that does not fit into a SIZExSIZE array
**	- The string must only contain digits between 1 and the array's size
**
**		returns
**
**	- 0						if the input is invalid
**	- size of the array		otherwise
**
**		params
**
**	- str:		string of characters that contains the input to check
**
** -------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------
**
**		format_input
**
**	Transforms a string of characters containing our input
**	in ascii form ;
**	To 4 arrays of ints containing our input in int form.
**	The 4 arrays will be allocated, filled and returned.
**
**	Each array of ints starts at position
**		I * size * 2				in the string
**	Each value contained in these arrays starts at position
**		I * size * 2  +  J * 2		in the string
**
**		returns
**
**	- address of the two-dimensional array of ints
**
**		params
**
**	- str:		string of characters that contains the input to format
**	- size:		amount of ints each array will hold
**
** -------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------
**
**		create_map
**
**	Allocates and returns a two-dimensional array of chars.
**	It will be used later on in the core recursive function
**	and be filled with characters between 1 and SIZE
**
**		returns
**
**	- adress of the two-dimensional array of chars
**
**		params
**
**	- size:		size of the array to create
**
** -------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------
**
**		box_puzzle
**
**	Main function which will :
**	- Check for the validity of our input
**	- Format that input in a 2d array of ints
**	- Create a 2d array of chars we will use as our playground
**	- Unleash the recursive function which will fill that playground
**		according to the rules of the game
**	- Depending on the return value of the recursive function,
**		- Print the map and return 1
**			or
**		- Return 0
**
**		returns
**
**	- 0		in case of error or if no solution was found
**	- 1		if a solution was found
**
**		params
**
**	- str:		the string containing our input
**				passed as parameter to our main
**
** -------------------------------------------------------------------- */
int	box_puzzle(char *str)
{
	int		size;
	int		**input;
	char	**map;
	int		xy[2];

	size = check_input(str);
	if (size < 1)
		return (0);
	input = format_input(str, size);
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

#include "box_puzzle.h"

int	mega_check(int **input, char **map, int size, int x, int y)
{
	char	bwcheck;
	char	line_r;
	char	line_l;
	char	col_t;
	char	col_b;

	bwcheck = backwards_check(map, x, y);
	line_l = 1;
	line_r = 1;
	col_t = 1;
	col_b = 1;
	if (y == size - 1)
	{
		line_r = line_right_check(input, map, size, x);
		line_l = line_left_check(input, map, size, x);
	}
	if (x == size - 1)
	{
		col_t = col_top_check(input, map, size, y);
		col_b = col_bot_check(input, map, size, y);
	}
	return (bwcheck && line_r && line_l && col_t && col_b);
}

int	box_recursive(int **input, char **map, int size, int x, int y)
{
	int		next_x;
	int		next_y;

	map[x][y] = 1;
	while (map[x][y] <= size)
	{
		if (mega_check(input, map, size, x, y))
		{
			if (y == size - 1 && x == size - 1)
				return (1);
			next_x = x;
			next_y = y + 1;
			if (y == size - 1)
			{
				next_y = 0;
				next_x = x + 1;
			}
			if (box_recursive(input, map, size, next_x, next_y))
				return (1);
		}
		map[x][y]++;
	}
	return (0);
}

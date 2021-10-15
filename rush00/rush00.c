void	ft_putchar(char c);

const char	BOTTOM_LEFT = 'C';
const char	BOTTOM_RIGHT = 'A';
const char	TOP_LEFT = 'A';
const char	TOP_RIGHT = 'C';
const char	LEFT = 'B';
const char	RIGHT = 'B';
const char	BOTTOM = 'B';
const char	TOP = 'B';
const char	MIDDLE = ' ';

// This function writes a TOP LEFT, TOP RIGHT, BOTTOM LEFT, BOTTOM RIGHT
// TOP, BOTTOM, LEFT, RIGHT or MIDDLE character depending on position in the rectangle
void	write_rectangle(int x, int y, int i, int j)
{
	if (i == 1)
	{
		if (j == 1)
			ft_putchar(TOP_LEFT);
		else if (j == y)
			ft_putchar(TOP_RIGHT);
		else
			ft_putchar(TOP);
	}
	else if (i == x)
	{
		if (j == 1)
			ft_putchar(BOTTOM_LEFT);
		else if (j == y)
			ft_putchar(BOTTOM_RIGHT);
		else
			ft_putchar(BOTTOM);
	}
	else
	{
		if (j == 1)
			ft_putchar(LEFT);
		else if (j == y)
			ft_putchar(RIGHT);
		else
			ft_putchar(MIDDLE);
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

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

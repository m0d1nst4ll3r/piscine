#include "box_puzzle.h"

int	main(int argc, char **argv)
{
	if (box_puzzle(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

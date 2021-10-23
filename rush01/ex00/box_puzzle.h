#ifndef __BOX_PUZZLE_H__
#define __BOX_PUZZLE_H__

#include <unistd.h>
#include <stdlib.h>

// box_puzzle_main.c
int	box_puzzle(int argc, char **argv);

// box_puzzle_core.c
int box_recursive(int **input, char **map, int size, int x, int y);

// box_puzzle_checks.c
int backwards_check(char **map, int x, int y);
int line_left_check(int **input, char **map, int size, int num);
int line_right_check(int **input, char **map, int size, int num);
int col_top_check(int **input, char **map, int size, int num);
int col_bot_check(int **input, char **map, int size, int num);

#endif

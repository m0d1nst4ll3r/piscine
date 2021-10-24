/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_puzzle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:00:33 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/24 20:14:19 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_PUZZLE_H
# define BOX_PUZZLE_H

# include <unistd.h>
# include <stdlib.h>

// box_puzzle_main.c
int	box_puzzle(char *str);

// box_puzzle_core.c
int	box_recursive(int **input, char **map, int size, int *xy);

// box_puzzle_checks.c
int	backwards_check(char **map, int x, int y);
int	line_left_check(char **map, int input, int size, int num);
int	line_right_check(char **map, int input, int size, int num);
int	col_top_check(char **map, int input, int size, int num);
int	col_bot_check(char **map, int input, int size, int num);

#endif

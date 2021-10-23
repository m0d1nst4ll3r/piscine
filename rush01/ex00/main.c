/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:00:00 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/23 14:00:03 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

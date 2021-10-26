/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c09_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:36:59 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/26 14:40:14 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap(int *a, int *b);
int		ft_strlen(char *str);

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int	a = 0;
	int	b = 42;

	ft_swap(&a, &b);
	ft_putchar('o');
	ft_putstr("pen");

	printf(", %d, %d, %d, %d\n", ft_strlen("Coucou"), ft_strcmp("eeeh", "eeeH"), a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c11_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:22:27 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 17:25:34 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_foreach(int *tab, int length, void(*f)(int));
int		*ft_map(int *tab, int length, int(*f)(int));
int		ft_count_if(char **tab, int length, int(*f)(char *));
int		ft_is_sort(int *tab, int length, int(*f)(int, int));
void	ft_sort_string_tab(char **tab);
void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

void	ft_printplusone(int nb)
{
	printf("%d\n", nb + 1);
}

int		ft_plusten(int nb)
{
	return(nb + 10);
}

int		ft_lengthtest(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i < 5 ? 1 : 0);
}

int		ft_cmp(int a, int b)
{
	return (a - b);
}

int		ft_cmpinv(int a, int b)
{
	return (b - a);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int	tab[] = {-8, -7, -6, -5, -4, 6, 7, 8, 9, 0};
	int	tab2[] = {-8, -7, -6, -5, -4, 6, 7, 8, 9, 10};
	int	tab3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	// ex00

	//ft_foreach(tab, 10, &ft_printplusone);


	// ex01

	/*int	*new;
	
	new = ft_map(tab, 10, &ft_plusten);
	for (int i = 0; i < 10; i++)
		printf("%d\n", new[i]);*/


	// ex02

	/*char	**strings;

	strings = malloc(80);
	strings[0] = "a";
	strings[1] = "ab";
	strings[2] = "abc";
	strings[3] = "abcd";
	strings[4] = "abcde";
	strings[5] = "abcdef";
	strings[6] = "abcdefg";
	strings[7] = "abcdefgh";
	strings[8] = "abcdefghi";
	strings[9] = "a";

	printf("%d\n", ft_count_if(strings, 10, &ft_lengthtest)); // 5*/


	// ex03

	//printf("%d\n", ft_is_sort(tab, 10, &ft_cmp));
	//printf("%d\n", ft_is_sort(tab2, 10, &ft_cmp));
	//printf("%d\n", ft_is_sort(tab3, 10, &ft_cmpinv));


	// ex06

	/*char	**tab;
	tab = malloc(80);
	tab[0] = "Salut";
	tab[1] = "\tles";
	tab[2] = "amis";
	tab[3] = "comment";
	tab[4] = "aaa";
	tab[5] = "303";
	tab[6] = "30";
	tab[7] = "002";
	tab[8] = "001";
	tab[9] = 0;
	ft_sort_string_tab(tab);
	for (int i = 0; i < 9; i++)
		printf("%s\n", tab[i]);*/


	// ex07

	char	**tab;
	tab = malloc(80);
	tab[0] = "Salut";
	tab[1] = "\tles";
	tab[2] = "amis";
	tab[3] = "comment";
	tab[4] = "aaa";
	tab[5] = "303";
	tab[6] = "30";
	tab[7] = "002";
	tab[8] = "001";
	tab[9] = 0;
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	for (int i = 0; i < 9; i++)
		printf("%s\n", tab[i]);
}

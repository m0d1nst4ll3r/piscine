/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c01_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:49:54 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/18 14:45:59 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

//	-----------------------------------------------------------------------
//
//								C01 C0RR3CT10NS
//
//	-----------------------------------------------------------------------

int	main(void)
{
	//ex00

	//int	n = 12;
	//ft_ft(&n);
	//printf("ex00 - %d\n", n);


	//ex01

	/*int n = 12;
	int *n1 = &n;
	int **n2 = &n1;
	int ***n3 = &n2;
	int ****n4 = &n3;
	int *****n5 = &n4;
	int ******n6 = &n5;
	int *******n7 = &n6;
	int ********n8 = &n7;
	int *********n9 = &n8;
	ft_ultimate_ft(n9);
	printf("ex01 - %d\n", n);*/


	//ex02

	/*int a = 12;
	int b = -6;
	ft_swap(&a, &b);
	printf("ex02 - %d, %d\n", a, b);*/


	//ex03

	/*int	a = 6;
	int b = -2;
	ft_div_mod(67, 5, &a, &b);
	printf("ex03 - %d, %d\n", a, b);*/


	//ex04

	/*int a = 67;
	int b = 5;
	ft_ultimate_div_mod(&a, &b);
	printf("ex04 - %d, %d\n", a, b);*/


	//ex05

	//ft_putstr("ex05 - 123abcABC%&$\t\f\v\b\r$\n\n");


	//ex06

	//char	c = 0;
	//printf("ex06 - %d, %d, %d\n", ft_strlen(&c), ft_strlen("0"), ft_strlen("01234567890123456789\n"));


	//ex07

	/*int	tab[] = {0,1,2,3,4,5,6,7,8,9};
	int tab2[] = {9,2,4};
	int	tab3[] = {0};
	ft_rev_int_tab(tab,10);
	ft_rev_int_tab(tab2,3);
	ft_rev_int_tab(tab3,1);
	printf("ex07 -\n");
	for (int i=0;i<10;i++)
		printf("%d",tab[i]);
	printf("\n");
	for (int i=0;i<3;i++)
		printf("%d",tab2[i]);
	printf("\n");
	for (int i=0;i<1;i++)
		printf("%d",tab3[i]);
	printf("\n");*/


	//ex08

	/*int	tab[] = {9,1,2,9,4,-5,6,-10,0,9}; // -10 -5 0 1 2 4 6 9 9 9
	int tab2[] = {2147483647,-2147483648,0}; // -2147483648 0 2147483647
	int	tab3[] = {1337}; // 1337
	ft_sort_int_tab(tab,10);
	ft_sort_int_tab(tab2,3);
	ft_sort_int_tab(tab3,1);
	printf("ex08 -\n");
	for (int i=0;i<10;i++)
		printf("%d ",tab[i]);
	printf("\n");
	for (int i=0;i<3;i++)
		printf("%d ",tab2[i]);
	printf("\n");
	for (int i=0;i<1;i++)
		printf("%d ",tab3[i]);
	printf("\n");*/
}

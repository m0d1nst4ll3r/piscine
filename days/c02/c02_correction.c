/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c02_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:30:36 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/21 17:43:13 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);
void	ft_print_memory(void *addr, unsigned int size);

//  -----------------------------------------------------------------------
//
//                              C02 C0RR3CT10NS
//
//  -----------------------------------------------------------------------

int		main()
{
	// ex00

	//char	dest[100];
	//printf("ex00 - %s\n", ft_strcpy(dest, "Salut 123 $$$\n$$$\t$$$"));


	// ex01

	/*char	dest[100];
	printf("ex01 - %s\n", ft_strncpy(dest, "Salut 123 $$$\n$$$\t$$$", 0));
	printf("ex01 - %s\n", ft_strncpy(dest, "Salut 123 $$$\n$$$\t$$$", 1));
	printf("ex01 - %s\n", ft_strncpy(dest, "Salut 123 $$$\n$$$\t$$$", 5));
	printf("ex01 - %s\n", ft_strncpy(dest, "Salut 123 $$$\n$$$\t$$$", 10));
	printf("ex01 - %s\n", ft_strncpy(dest, "Salut 123 $$$\n$$$\t$$$", 30));*/


	// ex02

	/*char	c = 0;
	printf("ex02 - %d\n", ft_str_is_alpha(&c));
	printf("ex02 - %d\n", ft_str_is_alpha("a"));
	printf("ex02 - %d\n", ft_str_is_alpha(" "));
	printf("ex02 - %d\n", ft_str_is_alpha("a "));
	printf("ex02 - %d\n", ft_str_is_alpha("Aa"));
	printf("ex02 - %d\n", ft_str_is_alpha("AawaweapOQWEQWPKeazmwpiWEp"));
	printf("ex02 - %d\n", ft_str_is_alpha("EQWOI5"));
	printf("ex02 - %d\n", ft_str_is_alpha("QWEIOjqwe\n"));*/


	// ex03

	/*char	c = 0;
	printf("ex03 - %d\n", ft_str_is_numeric(&c));
	printf("ex03 - %d\n", ft_str_is_numeric("6"));
	printf("ex03 - %d\n", ft_str_is_numeric(" "));
	printf("ex03 - %d\n", ft_str_is_numeric("3475837"));
	printf("ex03 - %d\n", ft_str_is_numeric("02348e"));*/


	// ex04
	
	/*char	c = 0;
	printf("ex04 - %d\n", ft_str_is_lowercase(&c));
	printf("ex04 - %d\n", ft_str_is_lowercase("h"));
	printf("ex04 - %d\n", ft_str_is_lowercase(" "));
	printf("ex04 - %d\n", ft_str_is_lowercase("lllL"));
	printf("ex04 - %d\n", ft_str_is_lowercase("lllqwejqejjpkepkvfon"));
	printf("ex04 - %d\n", ft_str_is_lowercase("lllqwejqejj@pkepkvfo"));*/


	// ex05

	/*char	c = 0;
	printf("ex05 - %d\n", ft_str_is_uppercase(&c));
	printf("ex05 - %d\n", ft_str_is_uppercase("W"));
	printf("ex05 - %d\n", ft_str_is_uppercase(" "));
	printf("ex05 - %d\n", ft_str_is_uppercase("OQWEJOIQWJEe"));
	printf("ex05 - %d\n", ft_str_is_uppercase("QWOEIJQWE&QWE"));*/


	// ex06

	/*char	c = 0;
	char	str[2] = {127, 0};
	char	str2[3] = {48, 5, 0};
	printf("ex06 - %d\n", ft_str_is_printable(&c));
	printf("ex06 - %d\n", ft_str_is_printable(str2));
	printf("ex06 - %d\n", ft_str_is_printable(str));
	printf("ex06 - %d\n", ft_str_is_printable("6"));
	printf("ex06 - %d\n", ft_str_is_printable(" "));
	printf("ex06 - %d\n", ft_str_is_printable("3475837"));
	printf("ex06 - %d\n", ft_str_is_printable("02348e"));*/


	// ex07

	/*char	c = 0;
	char	str[] = "Salut !";
	char	str2[] = "qwQWEQWoehqWEQWE503ejWQEioqQWEje&oiqwj%%eo%%iqjeo";

	printf("ex07 - %s\n", ft_strupcase(&c));
	printf("ex07 - %s\n", ft_strupcase(str));
	printf("ex07 - %s\n", ft_strupcase(str2));*/


	// ex08

	/*char	c = 0;
	char	str[] = "Salut !";
	char	str2[] = "qwQWEQWoehqWEQWE503ejWQEioqQWEje&oiqwj%%eo%%iqjeo";

	printf("ex08 - %s\n", ft_strlowcase(&c));
	printf("ex08 - %s\n", ft_strlowcase(str));
	printf("ex08 - %s\n", ft_strlowcase(str2));*/


	// ex09

	/*char	c = 0;
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("ex09 - %s\n", ft_strcapitalize(&c));
	printf("ex09 - %s\n", ft_strcapitalize(str));*/


	// ex10

	/*char	src[] = "src string 213014 WEQWJE &%$^\n\n\n$$$";
	char	src2 = 0;
	char	dest[100];
	char	dest2[100];

	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,src,0), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,src,0), dest2);
	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,src,1), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,src,1), dest2);
	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,src,2), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,src,2), dest2);
	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,src,25), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,src,25), dest2);
	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,src,50), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,src,50), dest2);
	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,src,-5), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,src,-5), dest2);
	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,&src2,0), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,&src2,0), dest2);
	printf("ex10 - strlcat: %ld|%s\n", strlcpy(dest,&src2,5), dest);
	printf("ex10 - custom : %d|%s\n", ft_strlcpy(dest2,&src2,5), dest2);*/


	// ex11

	//ft_putstr_non_printable("ff \xff 81 \x81 01 \x01 02 \x02 03 \x03 0f \x0f 10 \x10 1a \x1a 1f \x1f 7f \x7f end");


	// ex12

	void	*p = &p;
	int		i = 0;

	while (i++ < 32)
		ft_print_memory(p, i);

	//printf("ex12 - 01\n");
	//ft_print_memory(p, 3);
	//printf("ex12 - 02\n");
	//ft_print_memory(p, 0);
	//printf("ex12 - 03\n");
	//ft_print_memory(p, 1);
	//printf("ex12 - 04\n");
	//ft_print_memory(p, 15);
	//printf("ex12 - 05\n");
	//ft_print_memory(p, 16);
	//printf("ex12 - 06\n");
	//ft_print_memory(p, 17);
	//printf("ex12 - 07\n");
	//ft_print_memory(p, 956);
}

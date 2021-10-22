/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c03_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:30:36 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/21 17:58:20 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);


//  -----------------------------------------------------------------------
//
//                              C03 C0RR3CT10NS
//
//  -----------------------------------------------------------------------

int		main()
{
	// ex00

	/*char	c = 0;
	char	s[] = " ";
	char	s1[] = "01235";
	char	s2[] = "0123B";
	char	s3[] = "0123\n";
	char	s4[] = "01235 ";
	char	s5[] = "\n\n\n\t\b%^&$A";
	char	s6[] = "\n\n\n\t\b%^&$0z";

	if (strcmp(&c,&c) == ft_strcmp(&c,&c))
		printf("ex00 - test00 - SUCCESS\n");
	else
		printf("ex00 - test00 - FAILED\n");
	if (strcmp(&c,s) == ft_strcmp(&c,s))
		printf("ex00 - test01 - SUCCESS\n");
	else
		printf("ex00 - test01 - FAILED\n");
	if (strcmp(s,s) == ft_strcmp(s,s))
		printf("ex00 - test02 - SUCCESS\n");
	else
		printf("ex00 - test02 - FAILED\n");
	if (strcmp(s1,s2) == ft_strcmp(s1,s2))
		printf("ex00 - test03 - SUCCESS\n");
	else
		printf("ex00 - test03 - FAILED\n");
	if (strcmp(s1,s3) == ft_strcmp(s1,s3))
		printf("ex00 - test04 - SUCCESS\n");
	else
		printf("ex00 - test04 - FAILED\n");
	if (strcmp(s1,s4) == ft_strcmp(s1,s4))
		printf("ex00 - test05 - SUCCESS\n");
	else
		printf("ex00 - test05 - FAILED\n");
	if (strcmp(s5,s1) == ft_strcmp(s5,s1))
		printf("ex00 - test06 - SUCCESS\n");
	else
		printf("ex00 - test06 - FAILED\n");
	if (strcmp(s5,s6) == ft_strcmp(s5,s6))
		printf("ex00 - test07 - SUCCESS\n");
	else
		printf("ex00 - test07 - FAILED\n");*/


	// ex01

	/*char	c = 0;
	char	s[] = " ";
	char	s1[] = "01235";
	char	s2[] = "0123B";
	char	s3[] = "0123\n";
	char	s4[] = "01235 ";
	char	s5[] = "\n\n\n\t\b%^&$A";
	char	s6[] = "\n\n\n\t\b%^&$0z";

	if (strncmp(&c,&c,5) == ft_strncmp(&c,&c,5))
		printf("ex01 - test00 - SUCCESS\n");
	else
		printf("ex01 - test00 - FAILED\n");
	if (strncmp(&c,s,1) == ft_strncmp(&c,s,1))
		printf("ex01 - test01 - SUCCESS\n");
	else
		printf("ex01 - test01 - FAILED\n");
	if (strncmp(s,s,11) == ft_strncmp(s,s,11))
		printf("ex01 - test01 - SUCCESS\n");
	else
		printf("ex01 - test01 - FAILED\n");
	if (strncmp(s1,s2,2) == ft_strncmp(s1,s2,2))
		printf("ex01 - test02 - SUCCESS\n");
	else
		printf("ex01 - test02 - FAILED\n");
	if (strncmp(s1,s3,0) == ft_strncmp(s1,s3,0))
		printf("ex01 - test03 - SUCCESS\n");
	else
		printf("ex01 - test03 - FAILED\n");
	if (strncmp(s1,s4,1) == ft_strncmp(s1,s4,1))
		printf("ex01 - test04 - SUCCESS\n");
	else
		printf("ex01 - test04 - FAILED\n");
	if (strncmp(s5,s1,1) == ft_strncmp(s5,s1,1))
		printf("ex01 - test05 - SUCCESS\n");
	else
		printf("ex01 - test05 - FAILED\n");
	if (strncmp(s5,s6,7) == ft_strncmp(s5,s6,7))
		printf("ex01 - test06 - SUCCESS\n");
	else
		printf("ex01 - test06 - FAILED\n");*/
	

	// ex02

	/*char	dest[50] = "Coucou les";
	char	c = 0;

	printf("ex02: %s\n", ft_strcat(dest," am"));
	printf("ex02: %s\n", ft_strcat(dest,"is com"));
	printf("ex02: %s\n", ft_strcat(dest,"ment"));
	printf("ex02: %s\n", ft_strcat(dest," "));
	printf("ex02: %s\n", ft_strcat(dest,&c));
	printf("ex02: %s\n", ft_strcat(dest,"ça va ?\n$$$"));*/


	// ex03

	/*char	dest[50] = "Coucou les";
	char	c = 0;

	printf("ex02: %s\n", ft_strncat(dest," am",0));
	printf("ex02: %s\n", ft_strncat(dest,"is com",4));
	printf("ex02: %s\n", ft_strncat(dest,"ment",9));
	printf("ex02: %s\n", ft_strncat(dest," ",1));
	printf("ex02: %s\n", ft_strncat(dest,&c,5));
	printf("ex02: %s\n", ft_strncat(dest,"ça va ?\n$$$",7));*/


	// ex04

	/*char	hay[] = "As of Ubunutu 14.04 'screenshot of window' only takes t&&&&&he part in the current workspace. $&%For example if y%our window spans more than one vis42ible workspace, be0987cause it is longer or tttawider, then only the pict  kure is cropped to the current workspace";
	char	c = 0;

	if (strstr(hay,"14.04") == ft_strstr(hay,"14.04"))
		printf("ex04 - test00 - SUCCESS\n");
	else
		printf("ex04 - test00 - FAILED\n");
	if (strstr(hay,"U") == ft_strstr(hay,"U"))
		printf("ex04 - test01 - SUCCESS\n");
	else
		printf("ex04 - test01 - FAILED\n");
	if (strstr(hay,"u") == ft_strstr(hay,"u"))
		printf("ex04 - test01 - SUCCESS\n");
	else
		printf("ex04 - test01 - FAILED\n");
	if (strstr(hay,"t") == ft_strstr(hay,"t"))
		printf("ex04 - test02 - SUCCESS\n");
	else
		printf("ex04 - test02 - FAILED\n");
	if (strstr(hay,"42") == ft_strstr(hay,"42"))
		printf("ex04 - test03 - SUCCESS\n");
	else
		printf("ex04 - test03 - FAILED\n");
	if (strstr(hay,"7676767") == ft_strstr(hay,"7676767"))
		printf("ex04 - test04 - SUCCESS\n");
	else
		printf("ex04 - test04 - FAILED\n");
	if (strstr(hay,"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww") == ft_strstr(hay,"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"))
		printf("ex04 - test05 - SUCCESS\n");
	else
		printf("ex04 - test05 - FAILED\n");
	if (strstr(hay,"As of Ubunutu 14.04 'screenshot of window' only takes t&&&&&he part in the current workspace. $&%For example if y%our window spans more than one vis42ible workspace, be0987cause it is longer or tttawider, then only the pict  kure is cropped to the current workspace") == ft_strstr(hay,"As of Ubunutu 14.04 'screenshot of window' only takes t&&&&&he part in the current workspace. $&%For example if y%our window spans more than one vis42ible workspace, be0987cause it is longer or tttawider, then only the pict  kure is cropped to the current workspace"))
		printf("ex04 - test06 - SUCCESS\n");
	else
		printf("ex04 - test06 - FAILED\n");
	if (strstr(hay,"As of Ubunutu 14.04 'screenshot of window' only takes t&&&&&he part in the current workspace. $&%For example if y%our window spans more than one vis42ible workspace, be0987cause it is longer or tttawider, then only the pict  kure is cropped to the current workspace ") == ft_strstr(hay,"As of Ubunutu 14.04 'screenshot of window' only takes t&&&&&he part in the current workspace. $&%For example if y%our window spans more than one vis42ible workspace, be0987cause it is longer or tttawider, then only the pict  kure is cropped to the current workspace "))
		printf("ex04 - test07 - SUCCESS\n");
	else
		printf("ex04 - test07 - FAILED\n");
	if (strstr(&c,"test") == ft_strstr(&c,"test"))
		printf("ex04 - test08 - SUCCESS\n");
	else
		printf("ex04 - test08 - FAILED\n");
	if (strstr(&c,&c) == ft_strstr(&c,&c))
		printf("ex04 - test09 - SUCCESS\n");
	else
		printf("ex04 - test09 - FAILED\n");
	if (strstr(hay,&c) == ft_strstr(hay,&c))
		printf("ex04 - test10 - SUCCESS\n");
	else
		printf("ex04 - test10 - FAILED\n");*/


	// ex05
}

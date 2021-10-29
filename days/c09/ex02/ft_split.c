/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:25:59 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/25 17:53:11 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

//	Tries to find c in str
//	Returns 1 when successful, 0 otherwise
int	ft_strfind(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

//	Returns the size of a word starting at str
//	Parses the string until it encounters one of
//		[charset]'s characters in the string
int	ft_getwordsize(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && ! ft_strfind(charset, str[i]))
		i++;
	return (i);
}

//	Fills array with words that it will allocate on the fly
//	Makes sure to end each word with a 0
//	Uses ft_getwordsize to know word size in advance
char	**ft_fillwords(char *str, char *charset, char **array)
{
	int	i;
	int	j;
	int	wordlen;
	int	word;

	i = -1;
	word = 0;
	while (str[++i])
	{
		if (! ft_strfind(charset, str[i]))
		{
			wordlen = ft_getwordsize(str + i, charset);
			j = -1;
			array[word] = malloc(sizeof(*array[i]) * (wordlen + 1));
			if (array[word] == NULL)
				return (NULL);
			while (++j < wordlen)
				array[word][j] = str[i + j];
			array[word++][j] = 0;
			i += j;
		}
	}
	array[word] = 0;
	return (array);
}

//	Will count the amount of strings of characters separated by [charset]
//		in the string.
//	This is done by using a "boolean" [inword] which will tell us whether
//		we just entered a word, or left one.
int	ft_countwords(char *str, char *charset)
{
	int		i;
	int		words;
	char	inword;

	i = 0;
	words = 0;
	inword = 0;
	while (str[i])
	{
		if (! inword && ! ft_strfind(charset, str[i]))
		{
			words++;
			inword = 1;
		}
		else if (inword && ft_strfind(charset, str[i]))
			inword = 0;
		i++;
	}
	return (words);
}

//	First, allocates an array of strings of the right size
//		by counting words with ft_countwords (including the last 0)
//	Then, allocates each string of the right size by counting
//		characters and fills them with the words
//		by using ft_fillwords
char	**ft_split(char *str, char *charset)
{
	char	**array;

	array = malloc(sizeof(*array) * (ft_countwords(str, charset) + 1));
	if (array == NULL)
		return (NULL);
	if (ft_fillwords(str, charset, array) == NULL)
		return (NULL);
	return (array);
}

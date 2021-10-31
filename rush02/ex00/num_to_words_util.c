/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:04:22 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 21:14:21 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_puterr
**
**	Displays str on stderr
** -------------------------------------------------------------------- */
void	ntw_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

/* -----------------------------------------------------------------------
**		ntw_putstr
**
**	Displays str on stdout
** -------------------------------------------------------------------- */
void	ntw_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

/* -----------------------------------------------------------------------
**		ntw_open_dic
**
**	Attempts to open the dictionary
**	Will check if it's not a directory
**	In case of error or if dic is a dictionary, returns -1
**
**		params
**
**	- dic:		the dictionary's filename
** -------------------------------------------------------------------- */
int	ntw_open_dic(char *dic)
{
	int	fd;

	fd = open(dic, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		return (open(dic, O_RDONLY));
	else
	{
		close(fd);
		return (-1);
	}
}

/* -----------------------------------------------------------------------
**		ntw_realloc
**
**	Will free a string and return a copy of it with one extra character
**		added at the end
**	Preserves the null termination
**	This function is used extensively to handle file reading
**
**		params
**
**	- old:		the old string to duplicated and free
**	- add:		the character to add to the new string
** -------------------------------------------------------------------- */
char	*ntw_realloc(char *old, char add)
{
	int		i;
	char	*new;

	i = 0;
	while (old && old[i])
		i++;
	new = malloc(sizeof(*new) * (i + 2));
	if (! new)
		return (old);
	if (old)
	{
		i = -1;
		while (old[++i])
			new[i] = old[i];
		free(old);
	}
	new[i] = add;
	new[i + 1] = 0;
	return (new);
}

/* -----------------------------------------------------------------------
**		ntw_convert_key
**
**	This function will take in a correctly formatted unsigned number
**		as argument, such as "0", "10", "1000",
**		or "1238951954159061856", in the form of a string
**	It will then decide whether to return that value as an int,
**		or compress it and return it as a negative integer
**	If the number has 3 digits or less, it will be converted to an int
**	If the number has more than 3, and is a power of 1000, it will be
**		compressed accordingly
**	Otherwise, 101 is returned, effectively ignoring the number
**	This is used to compress very big numbers into manageable sizes
**	We ignore more than 3 digits non-powers of 1000 because we won't ever
**		need them
**	1000^n is compressed as -n
**
**		params
**
**	- key:		the number to convert (in string form)
**
**		returns
**
**	- int value which will most likely not go below -128
**		and never above 999
** -------------------------------------------------------------------- */
int	ntw_convert_key(char *key)
{
	int	i;

	if (! key)
		return (102);
	i = 0;
	while (key[i])
		i++;
	if (i <= 3)
		return ntw_atoi(key);
	else
	{
		if (key[0] == '1')
		{
			i = 1;
			while (key[i] == '0')
				i++;
			if (! key[i] && (i - 1) % 3 == 0)
				return (0 - (i - 1) / 3);
		}
	}
	return (101);
}

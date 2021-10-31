/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:59:14 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 20:02:41 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_format_endline
**
**	When we reach the end of a non-empty line in our dictionary,
**		this function will be called and insert a new t_pair
**		element into our list, which will contain:
**			- The (compressed) number as a single char
**			- The word as a string
**
**	According to our compression rules, any value above 100 will
**		either be ignored (because it would be useless to us)
**		or will be compressed, if it is a power of 1000
**	The compression algorithm is:
**		1000^n		->			-n
**
**	Note that we check for duplicates, and we will ignore them.
**
**	Finally, we free the number's string before resetting both
**		addresses so that new allocations can be done.
**
**		params
**
**	- list:		the chained list that will be filled at the end of each
**				non-empty line
**	- strs:		the two strings we have filled
**				strs[0] is the number
**					it will be compressed into a single char
**				strs[1] is the word
**					it will be kept as-is and put into our list
** -------------------------------------------------------------------- */
void	ntw_format_endline(t_pair **list, char *strs[2])
{
	int	num;

	if (strs[0] && strs[1])
	{
		num = ntw_convert_key(strs[0]);
		if (num <= 100)
		{
			if (! ntw_seek_elem(*list, num))
				ntw_insert_elem(list, (char)num, strs[1]);
		}
	}
	if (! strs[0])
		free(strs[1]);
	free(strs[0]);
	strs[0] = 0;
	strs[1] = 0;
}

/* -----------------------------------------------------------------------
**		ntw_format_step, ntw_format_step2
**
**	Update our step based on what character we're seeing
**		as well as what step we're currently at
**	When reaching a number or word, will allocate memory byte by byte
**		with ntw_realloc to fill strings with the contents
**	We already know the dictionary is valid and can take liberties
**	Once we reach the end of a non-empty line, we will insert
**		a new element into our list with the corresponding
**		(compressed) key, and word
**		respectively as a char, and a string
**
**	The steps are defined as follows:
**
**	0:	We are skipping characters before our number
**		- If we find a '0', go to step 1
**		- If we find a non-'0' digit, go to step 2
**		- If we find anything else (tab, space, or newline), do nothing
**	1:	We are at the 0s preceding our number
**		- If we find a non-'0' digit, go to step 2 and
**			begin allocating a string
**		- If we find a tab, space, or colon, go to step 3 and
**			allocate a string with "0" in it
**		- If we find anything else ('0'), do nothing
**	2:	We are in our number, we are allocating it into a string
**		- If we find a digit, continue allocating the string
**		- If we find anything else (space, or colon), go to step 3
**	3:	We have allocated our number and skipping characters before our word
**		- If we find a non-space printable character, go to step 4 and
**			begin allocating a string
**		- If we find anything else, do nothing (space or colon)
**	4:	We are in our word, we are allocating it into a string
**		- If we find any printable character, continue allocating the string
**		- If we find a newline, insert a new element into our list with
**			the conversion of the number string as "num" (if below 101)
**			and the word string as "word"
**			free the number string, and set both pointers to 0
**			and go to step 0
**
**	Note that when we do nothing, we simply go back to the buffer parsing
**		and look at the next byte, and so on...
**
**		params
**
**	- step:		the step variable which will be between 0 and 4
**	- c:		the character, or byte, we are looking at
**	- list:		the chained list that will be filled at the end of each
**				non-empty line
**	- strs:		the two strings we will fill
**				strs[0] is the number
**				strs[1] is the word
** -------------------------------------------------------------------- */
void	ntw_format_step2(int *step, char c, t_pair **list, char *strs[2])
{
	if (*step == 3 && c >= 33 && c <= 126)
	{
		*step = 4;
		strs[1] = ntw_realloc(strs[1], c);
	}
	else if (*step == 4 && c >= 32 && c <= 126)
	{
		strs[1] = ntw_realloc(strs[1], c);
	}
	else if (*step == 4)
	{
		ntw_format_endline(list, strs);
		*step = 0;
	}
}

void	ntw_format_step(int *step, char c, t_pair **list, char *strs[2])
{
	if (*step == 0 && c == '0')
	{
		*step = 1;
	}
	else if (*step == 0 && c >= '1' && c <= '9')
	{
		*step = 2;
		strs[0] = ntw_realloc(strs[0], c);
	}
	else if (*step == 1 && c >= '1' && c <= '9')
	{
		*step = 2;
		strs[0] = ntw_realloc(strs[0], c);
	}
	else if (*step == 1 && (c == ' ' || c == ':'))
	{
		*step = 3;
		strs[0] = ntw_realloc(strs[0], '0');
	}
	else if (*step == 2 && (c == ' ' || c == ':'))
		*step = 3;
	else if (*step == 2)
		strs[0] = ntw_realloc(strs[0], c);
	else
		ntw_format_step2(step, c, list, strs);
}

/* -----------------------------------------------------------------------
**		ntw_format_buff
**
**	Reads from the provided file descriptor, and for each byte
**		of each buffer, will handle what to do with that byte
**		by calling ntw_format_step.
**
**	Uses a step system to know what to do with a byte. It will either:
**		- Skip the byte without doing anything
**		- Allocate or re-allocate a string to save the byte in memory
**		- Insert a new element into our list
**			at the end of each non-empty line
**	Steps will be incremented and reset accordingly.
**
**		params
**
**	- step:		the step variable we will use throughout the formatting
**	- fd:		the dictionary's valid file descriptor
**	- list:		the list we will fill
** --------------------------------------------------------------------- */
void	ntw_format_buf(int *step, int fd, t_pair **list)
{
	int		i;
	char	buf[BUFSIZE];
	int		size;
	char	*strs[2];

	size = read(fd, buf, BUFSIZE);
	strs[0] = 0;
	strs[1] = 0;
	while (size)
	{
		i = 0;
		while (i < size)
		{
			ntw_format_step(step, buf[i], list, strs);
			i++;
		}
		size = read(fd, buf, BUFSIZE);
	}
}

/* -----------------------------------------------------------------------
**		ntw_format_dic
**
**	Attempts to open the dictionary file to prepare the terrain
**		for ntw_format_buff which will then parse that file,
**		and format its entries into a list
**	Declares and initializes both the step value we will use
**		throughout our formatting, and the list we will fill
**		with entries.
**
**		params
**
**	- dic:		the dictionary's filename
** --------------------------------------------------------------------- */
t_pair	*ntw_format_dic(char *dic)
{
	int		fd;
	int		step;
	t_pair	*list;

	fd = ntw_open_dic(dic);
	if (fd == -1)
		return (0);
	step = 0;
	list = 0;
	ntw_format_buf(&step, fd, &list);
	close(fd);
	return (list);
}

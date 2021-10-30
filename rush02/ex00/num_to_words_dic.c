/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words_dic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:56:15 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 20:02:21 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num_to_words.h"

//	Open the dictionary, if it's not a directory, return its fd
//	Otherwise, return -1
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

//	Update our step based on what character we're seeing
//	If an error is found, return 1
//	Otherwise, return 0
//
//	The steps are defined as follows:
//
//	0:	We are at the beginning of a line
//		If we find a newline, everything is ok and we do nothing
//		If we find a space or tab, we are at step 1
//		If we find a digit, we are at step 2
//		If we find anything else, it's an error
//	1:	We are skipping the spaces and tabs before a digit
//		If we find a space or a tab, everything is ok and we do nothing
//		If we find a digit, we are at step 2
//		If we find anything else, it's an error
//	2:	We are looking at digits
//		If we find a digit, everything is ok and we do nothing
//		If we find a space, we are at step 3
//		If we find a colon, we are at step 4
//		If we find anything else, it's an error
//	3:	We are skipping the spaces after a digit
//		If we find a space, everything is ok and we do nothing
//		If we find a colon, we are at step 4
//		If we find anything else, it's an error
//	4:	We just passed a colon and are skipping the spaces before a word
//		If we find a space, everything is ok and we do nothing
//		If we find a printable, non-space character, we are at step 5
//		If we find anything else, it's an error
//	5:	We are looking at our word and its end of line spaces
//		If we find a printable character, everything is ok and we do nothing
//		If we find a newline, we are back at step 0
//		If we find anything else, it's an error
//
//	Note that the function is built so that we only enter an if
//		when we have to update step or when we find an error
//	Otherwise, we simply will return 0
int	ntw_update_step2(int *step, char c)
{
	if (*step == 3 && c == ':')
		*step = 4;
	else if (*step == 3 && c != ' ')
		return (1);
	else if (*step == 4 && c >= 33 && c <= 126)
		*step = 5;
	else if (*step == 4 && c != ' ')
		return (1);
	else if (*step == 5 && c == '\n')
		*step = 0;
	else if (*step == 5 && (c <= 31 || c >= 127))
		return (1);
	return (0);
}

int	ntw_update_step1(int *step, char c)
{
	if (*step == 0 && (c == ' ' || c == '\t'))
		*step = 1;
	else if (*step == 0 && c >= '0' && c <= '9')
		*step = 2;
	else if (*step == 0 && c != '\n')
		return (1);
	else if (*step == 1 && c >= '0' && c <= '9')
		*step = 2;
	else if (*step == 1 && c != ' ' && c != '\t')
		return (1);
	else if (*step == 2 && c == ' ')
		*step = 3;
	else if (*step == 2 && c == ':')
		*step = 4;
	else if (*step == 2 && (c < '0' || c > '9'))
		return (1);
	else if (*step > 2)
		return (ntw_update_step2(step, c));
	return (0);
}

int	ntw_check_buf(int *step, char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ntw_update_step1(step, buf[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ntw_check_dic(char *dic)
{
	int		fd;
	int		size;
	int		step;
	char	buf[BUFSIZE];

	fd = ntw_open_dic(dic);
	if (fd == -1)
		return (1);
	size = read(fd, buf, BUFSIZE);
	step = 0;
	while (size)
	{
		if (ntw_check_buf(&step, buf, size))
		{
			printf("Error.\nStep was %d\n", step);
			return (2);
		}
		size = read(fd, buf, BUFSIZE);
	}
	return (0);
}
